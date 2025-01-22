#pragma once
#include "Singleton.h"
#include "Actor.h"

#define ACTOR_CHAR "|- "

class ActorManager : public Singleton<ActorManager>
{
	set<Actor*> allActors;

public:
	FORCEINLINE set<Actor*> GetAllActors() const
	{
		return allActors;
	}
	FORCEINLINE void AddActor(Actor* _actor)
	{
		allActors.insert(_actor);
		_actor->BeginPlay();
	}
	FORCEINLINE void RemoveActor(Actor* _actor)
	{
		allActors.erase(_actor);
		_actor->BeginDestroy();
	}

public:
	~ActorManager();

	void BeginPlay();
	void Tick(const float _deltaTime);
	void BeginDestroy();

	void DisplayHierarchy() const;

private:
	string GetChildren(Actor* _actor, string _text="", const u_int& _level = 1) const;
};