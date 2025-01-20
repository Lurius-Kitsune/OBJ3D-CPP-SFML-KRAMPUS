#pragma once
#include "Actor.h"
class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	// Soft référence (Prefab)
	SubClassOf<Actor>* actorRef;

public:
	Spawner();
	~Spawner();

public:
	template <typename T>
	void Spawn(const SubClassOf<T>& _actorRef)
	{
		T* _actor = new T(_actorRef.GetObject());
		const Vector2f& _spawnPosition =
		{
			RandomValue(0.0f, spawnRange),
			RandomValue(0.0f, spawnRange),
		};
		_actor->SetPosition(_spawnPosition);

		LOG(Display, "J'ai Spawn");
	}
private:
	virtual void BeginPlay() override;
	void Spawn_Internal();
};

