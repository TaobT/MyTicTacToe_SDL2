#include "RenderableComponent.h"

bool RenderableComponent::Init() {
	positionComponent = GetOwner()->GetComponent<PositionComponent>();
	if (positionComponent.expired()) {
		return false;
	}
	return true;
}