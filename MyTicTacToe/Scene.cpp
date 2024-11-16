#include "Scene.h"
#include "RenderableComponent.h"

void Scene::AddActor(std::shared_ptr<Actor> actor) {
	actors.push_back(actor);
	auto renderable = std::weak_ptr<RenderableComponent>(actor->GetComponent<RenderableComponent>());
	renderables.push_back(renderable);
}

void Scene::Init() {
	for (auto it = actors.begin(); it != actors.end(); ++it) {
		(*it)->Init();
	}
}

void Scene::Update(int deltaMs) {
	for (auto it = actors.begin(); it != actors.end(); ++it) {
		(*it)->Update(deltaMs);
	}
}

void Scene::Render(SDL_Renderer* renderer) {
	for (auto renderable : renderables) {
		renderable.lock()->Render(renderer);
	}
}

void Scene::Cleanup() {
	for (auto actor : actors) {
		actor->Destroy();
	}
	actors.clear();
}