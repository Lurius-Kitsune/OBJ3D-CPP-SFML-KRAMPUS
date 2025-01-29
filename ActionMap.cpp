#include "ActionMap.h"

Input::ActionMap::ActionMap()
{
	isActive = false;
	name = "DefaultActionMap";
	actions = map<string, Action*>();
}

void Input::ActionMap::Update(const EventInfo& _event)
{
	if (!isActive) return;

	for (const pair<string, Action*>& _action : actions)
	{
		
		// tester si _vent == _action.second->data.trigger;

		//_action.second->TryToExecute();

		// si oui execute la callback
	}
}
