#include "SceneManager.h"

#include "Debug.h"

void SceneManager::AddScene(Scene* scene) {
	DEBUG_LOG("Adding scene");
	scenes.push_back(std::move(scene));
}

void SceneManager::LoadScene(int index) {
	DEBUG_LOG("Loading scene ");
	currentScene = scenes[index];
	currentScene->Init();
}

void SceneManager::Update(int deltaMs) {
	currentScene->Update(deltaMs);
}

void SceneManager::Render(SDL_Renderer* renderer) {
	currentScene->Render(renderer);
}

void SceneManager::Cleanup() {
	for (auto it = scenes.begin(); it != scenes.end(); ++it) {
		(*it)->Cleanup();
	}
	scenes.clear();
}