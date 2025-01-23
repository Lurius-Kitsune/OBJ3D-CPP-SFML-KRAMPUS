#pragma once
#include "Actor.h"
#include "MeshActor.h"

class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	SubclassOf<MeshActor>* ref;

public:
	Spawner(const string& _name);
	Spawner(const Spawner& _other);
	~Spawner();

private:
	virtual void BeginPlay() override;
	void Spawn();
};