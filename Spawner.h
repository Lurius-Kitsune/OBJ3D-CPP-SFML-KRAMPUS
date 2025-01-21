#pragma once
#include "Actor.h"
#include "MeshActor.h"

class Spawner : public Actor
{
	float spawnRate;
	float spawnRange;
	SubClassOf<MeshActor>* ref;

public:
	Spawner();
	~Spawner();

private:
	virtual void BeginPlay() override;
	void Spawn_Internal();

public:
	template <typename T>
	void Spawn(const SubClassOf<T>& _ref)
	{
		LOG(Display, "Spawn");

		T* _actor = new T(_ref.GetObject());
		_actor->Construct();

		const Vector2f& _spawnPosition =
		{
		GetRandomNumberInRange(0.0f, spawnRange),
		GetRandomNumberInRange(0.0f, spawnRange),
		};
		_actor->SetPosition(_spawnPosition);
	}
};