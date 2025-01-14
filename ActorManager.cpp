#include "ActorManager.h"

ActorManager::~ActorManager()
{
	for (Actor* _actor : allActors)
	{
		delete _actor;
	}
}

void ActorManager::BeginPlay()
{
	for (Actor* _actor: allActors)
	{
		_actor->BeginPlay();
	}
}

void ActorManager::Tick(const float _deltaTime)
{
	for (Actor* _actor : allActors)
	{
		_actor->Tick(_deltaTime);
	}

	GarbageCollector();
}

void ActorManager::GarbageCollector()
{
	vector<Actor*> _actorToDestroy;
	for (Actor* _actor : allActors)
	{
		if (_actor->GetShape()->IsToDestroy())
		{
			_actorToDestroy.push_back(_actor);
		}
	}

	for (Actor* _actor : _actorToDestroy)
	{
		allActors.erase(_actor);
		delete _actor;
	}
}

void ActorManager::BeginDestroy()
{
	for (Actor* _actor : allActors)
	{
		_actor->BeginDestroy();
	}
}
