#include "ActorManager.h"

ActorManager::~ActorManager()
{
	for (pair<string, Actor*> _actorPair : allActors)
	{
		delete _actorPair.second;
	}
}


void ActorManager::BeginPlay()
{
	for (pair<string, Actor*> _actorPair : allActors)
	{
		_actorPair.second->BeginPlay();
	}
}

void ActorManager::Tick(const float _deltaTime)
{
	vector<Actor*> _garbage;

	for (pair<string ,Actor*> _actorPair : allActors)
	{
		Actor* _actor = _actorPair.second;
		_actor->Tick(_deltaTime);

		if (_actor->IsToDelete())
		{
			_garbage.push_back(_actor);
		}
	}

	for (Actor* _actor : _garbage)
	{
		_actor->Deconstruct();
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