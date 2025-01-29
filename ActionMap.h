#pragma once
#include "CoreMinimal.h"
#include "Action.h"

namespace Input
{
	class ActionMap
	{
		bool isActive;
		string name;
		map<string, Action*> actions;

	public:
		ActionMap();

	public:
		void Update(const EventInfo& _event);

		template <typename Type>
		const Type* Retrieve(const EventInfo& _event)
		{
			return _event->getIf<Type>();
		}
	};
}



