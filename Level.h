#pragma once
#include "CoreMinimal.h"
#include "Actor.h"


class Level
{

public:
	template<typename T = Actor>
	static T* SpawnActor(SubClassOf<T>& _ref)
	{
		T* _actor = new T(_ref.GetObject());
		_actor->Construct();
		return _actor;
	}
};

