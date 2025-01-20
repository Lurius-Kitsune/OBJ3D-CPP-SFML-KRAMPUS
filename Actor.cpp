#include "Actor.h"
#include "ActorManager.h"

Actor::Actor()
{
	root = CreateComponent<RootComponent>(this);
	Register();
}

Actor::Actor(const Actor& _actor)
{
	root = CreateComponent<RootComponent>(this);
	Register();
}


Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
}

void Actor::AddComponent(Component* _component)
{
	//if (GetComponent<decltype(_component)>()) return;
	components.insert(_component);
}

void Actor::RemoveComponent(Component* _component)
{
	components.erase(_component);
}

void Actor::BeginPlay()
{
}

void Actor::Tick(const float _deltaTime)
{
	for (Component* _component : components)
	{
		_component->Tick(_deltaTime);
	}
}

void Actor::BeginDestroy()
{
	for (Component* _component : components)
	{
		_component->BeginDestroy();
	}
}

void Actor::Deconstruct()
{
	M_ACTOR.RemoveActor(this);
}

void Actor::Register()
{
	M_ACTOR.AddActor(this);
}
