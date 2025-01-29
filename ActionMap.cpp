#include "ActionMap.h"

Input::ActionMap::ActionMap()
{
	isActive = false;
	name = "DefaultActionMap";
	actions = map<string, Action*>();
}

void Input::ActionMap::Update(const Trigger& _event)
{

	if (!isActive) return;
}
