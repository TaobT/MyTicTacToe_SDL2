#pragma once

#include <SDL.h>
#include <iostream>
#include "SceneManager.h"
#include "ActorFactory.h"

class GameApp {
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	bool isRunning;

	SceneManager sceneManager;
	ActorFactory actorFactory;
public:
	void Initialize(const char* title, int width, int height);
	void Run();
	void Clean();
private:
	void Update();
	void Render();
	void HandleEvents();
};