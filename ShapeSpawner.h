#pragma once
#include "Actor.h"
class ShapeSpawner : public Actor
{
public:
	ShapeSpawner(const function<void()>& _spawnFunction, const Time& _spawnRate, const Vector2f _range,
		const float _radius = 0.0f, const string& _path = "",
		const size_t& _pointCount = 30, const IntRect& _rect = IntRect());

	ShapeSpawner(const function<void()>& _spawnFunction, const Time& _spawnRate, const Vector2f _range,
		const Vector2f& _size, const string& _path = "",
		const IntRect& _rect = IntRect());
};

