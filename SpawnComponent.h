#pragma once
#include "Component.h"
#include "TimerManager.h"
class SpawnComponent : public Component
{
	Timer<MilliSec>* spawnTimer;
public:
	SpawnComponent(const function<void()>& _spawnFunction, const Vector2f& _size, const Time& _time)
	{
		spawnTimer = new Timer<MilliSec>(_spawnFunction, _time, true, true);
	}

};

