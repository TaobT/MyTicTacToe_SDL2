#pragma once

#include "Actor.h"
#include "RenderableComponent.h"

#include <SDL.h>
#include <vector>

class Scene {
public:
	friend class SceneManager;

	std::vector<std::shared_ptr<Actor>> actors;
	std::vector<std::weak_ptr<RenderableComponent>> renderables;

	void AddActor(std::shared_ptr<Actor> actor);


	void Update(int deltaMs);

	void Render(SDL_Renderer* renderer);

	void Cleanup();

private:
	void Init();
};