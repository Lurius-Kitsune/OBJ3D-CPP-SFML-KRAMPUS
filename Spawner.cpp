#include "Spawner.h"
#include "TimerManager.h"

Spawner::Spawner()
{
	spawnRate = 1.0f;
	spawnRange = 200.0f;
	actorRef = new SubClassOf<MeshActor>(MeshActor(20.0f, 30, "Cow"));
	//BeginPlay();
}

Spawner::~Spawner()
{
	delete actorRef;
}

void Spawner::BeginPlay()
{
	Super::BeginPlay();
	new Timer<Seconds>(bind(&Spawner::Spawn_Internal, this), Time(seconds(spawnRate)), true, true);
}

void Spawner::Spawn_Internal()
{
	Spawn(*actorRef);
}

