#pragma once
#include "Actor.h"
#include "TimerManager.h"

template <typename T>
class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	// Soft référence (Prefab)
	SubClassOf<T>* actorRef;

public:
	Spawner(SubClassOf<T>* _actorRef)
	{
		spawnRate = 1.0f;
		spawnRange = 200.0f;
		actorRef = _actorRef;
		BeginPlay();
	}
	~Spawner()
	{
		delete actorRef;
	}

public:
	void Spawn()
	{
		T* _actor = new T(actorRef->GetObject());
		const Vector2f& _spawnPosition =
		{
			RandomValue(0.0f, spawnRange),
			RandomValue(0.0f, spawnRange),
		};
		_actor->SetPosition(_spawnPosition);

		LOG(Display, "J'ai Spawn");
	}
private:
	virtual void BeginPlay() override
	{
		Super::BeginPlay();
		new Timer<Seconds>(bind(&Spawner::Spawn_Internal, this), Time(seconds(spawnRate)), true, true);
	}
	void Spawn_Internal()
	{
		Spawn();
	}
};

