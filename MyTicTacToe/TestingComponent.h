#pragma once

#include "ActorComponent.h"
#include <iostream>

#include "Debug.h"

class TestingComponent : public ActorComponent {
public:
	TestingComponent() : ActorComponent(typeid(TestingComponent)) {}

	const char* GetName() const override {
		return "TestingComponent";
	}

	bool Init(void) override {
		DEBUG_LOG("TestingComponent Init");
		return true;
	}

	void PostInit(void) override {
	}

	void Update(int deltaMs) override {
	}
};