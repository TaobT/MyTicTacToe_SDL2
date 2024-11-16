#include "ButtonComponent.h"

bool ButtonComponent::Init() {
	positionComponent = GetOwner()->GetComponent<PositionComponent>();
	if (positionComponent.expired()) {
		return false;
	}
	/*renderableComponent = GetOwner()->GetComponent<RenderableComponent>();
	if (renderableComponent.expired()) {
		return false;
	}*/
	return true;
}

void ButtonComponent::Update(int deltaMs) {
	auto position = positionComponent.lock()->GetPosition();
	Vector2 mousePosition = Vector2(0,0);

	SDL_GetMouseState(&mousePosition.x, &mousePosition.y);

	if (mousePosition.x >= position.x && mousePosition.x <= position.x + size.x &&
		mousePosition.y >= position.y && mousePosition.y <= position.y + size.y) {
		if (!isHovered) {
			if (onHover != nullptr) onHover();
			DEBUG_LOG("Button %s hovered", GetOwner()->GetType().c_str());
		}
		isHovered = true;
	}
	else {
		isHovered = false;
	}

	if (isHovered && SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		if (!isPressed) {
			if (onPressed != nullptr) onPressed();
			DEBUG_LOG("Button %s pressed", GetOwner()->GetType().c_str());
		}
		isPressed = true;
	}
	else {
		isPressed = false;
	}
}