#pragma once
#include "ActorComponent.h"
#include "Debug.h"

#include <vector>
#include <string>

typedef unsigned int ActorId;
typedef std::string ActorType;
	
class Actor {
public:
	typedef std::vector<std::shared_ptr<ActorComponent>> ActorComponents;

private:
	ActorType type;
	ActorId id;
	ActorComponents components;

public:
	explicit Actor(ActorId id, ActorType type);
	~Actor();

	bool Init(void);
	void PostInit(void);
	void Destroy(void);
	void Update(int deltaMs);
	
	ActorId GetId(void) const { return id; }

	void AddComponent(ActorComponent* component);
	
	template <typename T>
	std::shared_ptr<T> GetComponent() {
		for (auto& component : components) {
			auto result = std::dynamic_pointer_cast<T>(component);
			if (result) {
				return result;
			}
		}
		return nullptr;
	}

	ActorType GetType(void) const { return type; }
};