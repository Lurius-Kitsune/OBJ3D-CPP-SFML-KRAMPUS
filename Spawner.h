#pragma once
#include "Actor.h"
class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	Actor* actorRef;

public:
	FORCEINLINE void SetActorRef(Actor* _actorRef)
	{
		actorRef = _actorRef;
	}

public:
	Spawner();
	~Spawner();

public:
private:
	virtual void BeginPlay() override;
	void Spawn();
};

