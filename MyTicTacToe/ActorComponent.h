#pragma once

#include <memory>
#include <typeindex>

#include "Debug.h"


typedef std::type_index ComponentId;
typedef class Actor* ActorPtr;

class ActorComponent {
private:
	ComponentId id;
	ActorPtr owner = nullptr;
public:
	explicit ActorComponent(ComponentId id) : id(id) {}
	virtual ~ActorComponent() { 
		owner = nullptr;

		DEBUG_LOG("%s destroyed", typeid(*this).name());
	}

	virtual bool Init(void) { return true; }
	virtual void PostInit(void) {}
	virtual void Update(int deltaMs) {}

	ComponentId GetId(void) const { return id; }
	virtual const char* GetName() const = 0;

	void SetOwner(ActorPtr owner) { this->owner = owner; }
	ActorPtr GetOwner(void) { return owner; }
};