#pragma once
#include "Actor.h"
class ShapeSpawner : public Actor
{
public:
	ShapeSpawner(const function<void()>& _spawnFunction, const Time& _spawnRate, const Vector2f _range);
};

