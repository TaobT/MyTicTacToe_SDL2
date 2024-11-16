#pragma once

#include <SDL.h>
#include <iostream>
#include <functional>

#include "Vector2.h"

#include "Actor.h"
#include "ActorComponent.h"
#include "PositionComponent.h"
#include "RenderableComponent.h"


class ButtonComponent : public ActorComponent {
private:
	Vector2 size;
	bool isPressed = false;
	bool isHovered = false;

	std::function<void()> onPressed;
	std::function<void()> onHover;

	std::weak_ptr<PositionComponent> positionComponent;
	//std::weak_ptr<RenderableComponent> renderableComponent;
public:
	ButtonComponent(Vector2 size) : ActorComponent(typeid(ButtonComponent)), size(size) {}

	const char* GetName() const override {
		return "ButtonComponent";
	}

	bool Init() override;

	void Update(int deltaMs) override;

	bool IsPressed() const { return isPressed; }

	bool IsHovered() const { return isHovered; }
};