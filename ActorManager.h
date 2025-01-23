#pragma once
#include "Singleton.h"
#include "Actor.h"

class ActorManager : public Singleton<ActorManager>
{
	set<Actor*> allActors;
	multimap<string, u_int> actorsID;

public:
	FORCEINLINE set<Actor*> GetAllActors() const
	{
		return allActors;
	}
	FORCEINLINE void AddActor(Actor* _actor)
	{
		allActors.insert(_actor);
		actorsID.insert(pair<string, u_int>(_actor->GetName(), _actor->GetID()));
		_actor->BeginPlay();
	}
	FORCEINLINE void RemoveActor(Actor* _actor)
	{
		allActors.erase(_actor);
		using Iterator = multimap<string, u_int>::iterator;

		const pair<Iterator, Iterator>& _results = actorsID.equal_range(_actor->GetName());
		
		for (Iterator _it = _results.first; _it != _results.second; ++_it)
		{
			if (_it->second == _actor->GetID())
			{
				actorsID.erase(_it);
				break;
			}
		}
		_actor->BeginDestroy();
	}
	FORCEINLINE u_int GetCountByName(const string _name)
	{
		// COnnaitre le string suffix du nom donnée;

		// Je parcours tous les actors qui possèdent le même nom

		// Si cest le même
		// Je rajoute "_index" au nom actuel
		// Et reteste

		// Si aucun n'as le même nom, sa seras juste le nom
	}
public:
	~ActorManager();

	void BeginPlay();
	void Tick(const float _deltaTime);
	void BeginDestroy();
};