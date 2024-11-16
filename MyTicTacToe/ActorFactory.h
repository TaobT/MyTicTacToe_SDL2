#pragma once

#include "Actor.h"

class ActorFactory {
private:
	ActorId lastActorId;
public:
	ActorPtr CreateActor(const ActorType& type);
private:
	ActorId GetNextActorId(void) { return ++lastActorId; }
};