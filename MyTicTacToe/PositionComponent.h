#pragma once

#include "ActorComponent.h"
#include "Vector2.h"

class PositionComponent : public ActorComponent {
private:
	Vector2 position;
public:
	PositionComponent() : ActorComponent(typeid(PositionComponent)) {}

	const char* GetName() const override {
		return "PositionComponent";
	}

	bool Init() override {
		position = Vector2(0, 0);
		return true;
	}

	void PostInit() override {
	}

	void Update(int deltaMs) override {
	}

	Vector2 GetPosition() const {
		return position;
	}

	void SetPosition(Vector2 position) {
		this->position = position;
	}

	void SetPosition(float x, float y) {
		position.x = x;
		position.y = y;
	}
};