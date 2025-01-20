#include "Spawner.h"
#include "TimerManager.h"

Spawner::Spawner()
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	actorRef = new Actor();
}

Spawner::~Spawner()
{
	delete actorRef;
}

void Spawner::BeginPlay()
{
	new Timer(bind(&Spawner::Spawn, this), Time(seconds(spawnRate)), true, true);
}

void Spawner::Spawn()
{
	Actor* _actor = new Actor(*actorRef);
	const Vector2f& _spawnPosition = 
}
