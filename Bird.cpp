#include "Bird.h"

Bird::Bird() : MeshActor()
{
	
}

Bird::Bird(const Bird& _other) : MeshActor(_other)
{
   
}


void Bird::BeginPlay()
{
	Super::BeginPlay();
}

void Bird::Update(const float _deltaTime)
{
	Super::Update(_deltaTime);
}