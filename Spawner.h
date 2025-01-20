#pragma once
#include "Actor.h"
class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	// Soft r�f�rence (Prefab)
	SubClassOf<Actor>* actorRef;

public:
	Spawner();
	~Spawner();

public:
	void Spawn(SubClassOf<Actor>* _actorRef);
private:
	virtual void BeginPlay() override;
	void Spawn_Internal();
};

