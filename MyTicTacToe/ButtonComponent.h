#pragma once

#include <SDL.h>
#include "ActorComponent.h"
#include <iostream>

class ButtonComponent : public ActorComponent {
private:
	SDL_Rect buttonArea;
	SDL_Color color;
	bool isPressed = false;
	bool isHovered = false;
public:
	ButtonComponent(ComponentId id, SDL_Rect buttonArea, SDL_Color color) : ActorComponent(id), buttonArea(buttonArea), color(color) {}

	const char* GetName() const override {
		return "ButtonComponent";
	}

	bool Init(void) override {
		return true;
	}

	void PostInit(void) override {
	}


};