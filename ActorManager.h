#pragma once
#include "Singleton.h"
#include "Actor.h"

class ActorManager : public Singleton<ActorManager>
{
	multimap<string, Actor*> allActors;

public:
	FORCEINLINE multimap<string, Actor*> GetAllActors() const
	{
		return allActors;
	}
	FORCEINLINE void AddActor(Actor* _actor)
	{
		allActors[_actor->GetName()] = _actor;
		_actor->BeginPlay();
	}
	FORCEINLINE void RemoveActor(Actor* _actor)
	{
		allActors.erase(_actor->GetName());
		_actor->BeginDestroy();
	}
	FORCEINLINE u_int GetCountByName(const string _name)
	{
		u_int _count = 0;

		return _count;
	}
public:
	~ActorManager();

	void BeginPlay();
	void Tick(const float _deltaTime);
	void BeginDestroy();
};