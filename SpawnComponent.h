#pragma once
#include "Component.h"
#include "TimerManager.h"
class SpawnComponent : public Component
{
	Timer<Seconds>* spawnTimer;
public:
	SpawnComponent(Actor* _owner, const function<void()>& _spawnFunction, const Vector2f& _size, const Time& _time)
		: Component(_owner)
	{
		spawnTimer = new Timer<Seconds>(_spawnFunction, _time, true, true);
	}

};

