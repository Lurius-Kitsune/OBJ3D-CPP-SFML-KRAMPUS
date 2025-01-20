#pragma once
#include "Actor.h"
class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	Actor* actorRef;

public:
	Spawner();
	~Spawner();

private:
	virtual void BeginPlay() override;
	void Spawn();
};

