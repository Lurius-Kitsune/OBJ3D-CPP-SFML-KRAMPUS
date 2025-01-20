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

void Spawner::Spawn()
{
	Actor* _actor = new Actor(*actorRef);
	const Vector2f& _spawnPosition =
	{
		RandomValue(0.0f, spawnRange),
		RandomValue(0.0f, spawnRange),
	};
	_actor->SetPosition(_spawnPosition);

	LOG(Display, "J'ai Spawn");
}

void Spawner::BeginPlay()
{
	Super::BeginPlay();
	new Timer<Seconds>(bind(&Spawner::Spawn, this), Time(seconds(spawnRate)), true, true);
}

