#pragma once
#include "Singleton.h"
#include "Actor.h"

class ActorManager : public Singleton<ActorManager>
{
	set<Actor*> allActors;
	multimap<string, Actor*> actorsID;

public:
	FORCEINLINE set<Actor*> GetAllActors() const
	{
		return allActors;
	}
	FORCEINLINE void AddActor(Actor* _actor)
	{
		allActors.insert(_actor);
		actorsID.insert(pair<string, Actor*>(_actor->GetName(), _actor));
		_actor->BeginPlay();
	}
	FORCEINLINE void RemoveActor(Actor* _actor)
	{
		allActors.erase(_actor);
		using Iterator = multimap<string, Actor*>::iterator;

		const pair<Iterator, Iterator>& _results = actorsID.equal_range(_actor->GetName());
		
		for (Iterator _it = _results.first; _it != _results.second; ++_it)
		{
			if (_it->second == _actor)
			{
				actorsID.erase(_it);
				break;
			}
		}
		_actor->BeginDestroy();
	}
	FORCEINLINE string GetAvailableName(const string _name, const int _index = 1)
	{
		const string& _fullName = _name + "_" + to_string(_index);
		// COnnaitre le string suffix du nom donnée;
		using Iterator = multimap<string, Actor*>::iterator;
		const pair<Iterator, Iterator>& _results = actorsID.equal_range(_name);

		// Je parcours tous les actors qui possèdent le même nom
		for (Iterator _it = _results.first; _it != _results.second; ++_it)
		{
			// Si cest le même
			if (_it->second->GetName() == _fullName) continue;

			// Si aucun n'as le même nom
			return _fullName;
		}

		// Si aucun n'as le même nom, sa seras juste le nom
		return GetAvailableName(_name , _index+1);
	}
public:
	~ActorManager();

	void BeginPlay();
	void Tick(const float _deltaTime);
	void BeginDestroy();
};