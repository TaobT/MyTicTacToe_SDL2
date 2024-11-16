#pragma once

#pragma once

#include "Scene.h"

#include <iostream>

class SceneManager {
private:
	Scene* currentScene;
	std::vector<Scene*> scenes;
public:
	void AddScene(Scene* scene);

	void LoadScene(int index);

	void Update(int deltaMs);

	void Render(SDL_Renderer* renderer);

	void Cleanup();
};