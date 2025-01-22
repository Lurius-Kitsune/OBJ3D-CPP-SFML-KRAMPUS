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
	for (Actor* _actor : allActors)
	{
		_actor->BeginPlay();
	}
}

void ActorManager::Tick(const float _deltaTime)
{
	vector<Actor*> _garbage;
	for (Actor* _actor : allActors)
	{
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

void ActorManager::DisplayHierarchy() const
{
	system("cls");
	string _display = "\n\n";
	for (Actor* _actor : allActors)
	{
		if (_actor->GetParent()) continue;
		_display += ACTOR_CHAR + _actor->GetName() + "\n";
		if (!_actor->GetChildren().empty())
		{
			_display += GetChildren(_actor);
		}
	}

	LOG(Display, _display);
}

string ActorManager::GetChildren(Actor* _actor, string _text, const u_int& _level) const
{

	if (_actor->GetChildren().empty())
	{
		for (u_int _i = 0; _i < _level; _i++)
		{
			_text += string("   ");
		}
		_text += string(ACTOR_CHAR + _actor->GetName() + "\n");
		return _text;
	}

	for (Actor* _child : _actor->GetChildren())
	{
		_text += GetChildren(_child, _text, _level + 1);
	}

	return _text;

}


