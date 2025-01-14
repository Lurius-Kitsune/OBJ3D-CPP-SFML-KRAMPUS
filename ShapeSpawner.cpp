#include "ShapeSpawner.h"
#include "SpawnComponent.h"

ShapeSpawner::ShapeSpawner(const function<void()>& _spawnFunction, const Time& _spawnRate, const Vector2f _range, const float _radius, const string& _path, const size_t& _pointCount, const IntRect& _rect)
	: Actor(_radius, _path, _pointCount, _rect)
{
	AddComponent(new SpawnComponent(_spawnFunction, _range, _spawnRate));
}

ShapeSpawner::ShapeSpawner(const function<void()>& _spawnFunction, const Time& _spawnRate, const Vector2f _range, const Vector2f& _size, const string& _path, const IntRect& _rect)
	: Actor(_size, _path, _rect)
{
	AddComponent(new SpawnComponent(_spawnFunction, _range, _spawnRate));
}
