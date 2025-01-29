#include "InputManager.h"


void Input::InputManager::Update(RenderWindow& _window)
{
    while (const EventInfo& _event = _window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            _window.close();
            return;
        }
        UpdateActionMap(_event);
    }
}

void Input::InputManager::UpdateActionMap(const EventInfo& _event)
{

    for(ActionMap* _map : actionMaps)
	{
        _map->Update(_event);
	}
}
