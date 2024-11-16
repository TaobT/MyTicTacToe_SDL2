#include "Actor.h"

Actor::Actor(ActorId id, ActorType type) : id(id), type(type) {}

Actor::~Actor() {
	components.clear();

	DEBUG_LOG("Actor %s deconstructed", type.c_str());
}

bool Actor::Init(void) {
	for (auto component : components) {
		if (!component->Init()) {
			return false;
		}
	}
	return true;
}

void Actor::PostInit(void) {
	for (auto component : components) {
		component->PostInit();
	}
}

void Actor::Destroy(void) {
	components.clear();
	DEBUG_LOG("Actor %s destroyed", type.c_str());
}

void Actor::Update(int deltaMs) {
	for (auto component : components) {
		component->Update(deltaMs);
	}
}

void Actor::AddComponent(ActorComponent* component) {
	DEBUG_LOG("Adding component: %s", component->GetName());
	components.push_back(std::shared_ptr<ActorComponent>(component));
	component->SetOwner(ActorPtr(this));
}