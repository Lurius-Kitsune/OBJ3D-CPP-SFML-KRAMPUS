#pragma once
#include "Singleton.h"
#include "ActionMap.h"

namespace Input
{
	class InputManager : public Singleton<InputManager>
	{
		set<ActionMap*> actionMaps;
	
	public:
		void Update(RenderWindow& _window);
	private:
		void UpdateActionMap(const EventInfo& _event);
	};
}

