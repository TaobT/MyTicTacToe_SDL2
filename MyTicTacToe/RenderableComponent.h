#pragma once

#include <SDL.h>

#include "ActorComponent.h"
#include "Actor.h"
#include "PositionComponent.h"

class RenderableComponent : public ActorComponent {
private:
	std::weak_ptr<PositionComponent> positionComponent;
public:
	RenderableComponent() : ActorComponent(typeid(RenderableComponent)) {}

	const char* GetName() const override {
		return "RenderableComponent";
	}

	bool Init() override;

	void PostInit(void) override {
	}

	void Update(int deltaMs) override {
	}

	void Render(SDL_Renderer* renderer) {
		Vector2 position = positionComponent.lock()->GetPosition();
		SDL_Rect rect;
		rect.x = position.x;
		rect.y = position.y;
		rect.w = 100;
		rect.h = 100;
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
		SDL_RenderFillRect(renderer, &rect);
	}
};