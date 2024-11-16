#include "ActorFactory.h"

ActorPtr ActorFactory::CreateActor(const ActorType& type) {
	ActorId newId = GetNextActorId();
	ActorPtr newActor(new Actor(newId, type));
	if (!newActor->Init()) {
		return ActorPtr();
	}
	newActor->PostInit();
	return newActor;
}