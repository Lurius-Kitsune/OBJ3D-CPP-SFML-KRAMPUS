#include "ShapeSpawner.h"
#include "SpawnComponent.h"

ShapeSpawner::ShapeSpawner(const function<void()>& _spawnFunction, const Time& _spawnRate, const Vector2f _range)
	: Actor()
{
	AddComponent(new SpawnComponent(this,_spawnFunction, _range, _spawnRate));
}

