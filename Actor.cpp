#include "Actor.h"
#include "ActorManager.h"

Actor::Actor()
{
	isToDelete = false;
	root = CreateComponent<RootComponent>();
}

Actor::Actor(const Actor& _actor)
{
	isToDelete = false;
	root = CreateComponent<RootComponent>(*_actor.root);
}

Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
}


void Actor::Construct()
{
	M_ACTOR.AddActor(this);
}

void Actor::Deconstruct()
{
	M_ACTOR.RemoveActor(this);
}

void Actor::BeginPlay()
{
	for (Component* _component : components)
	{
		_component->BeginPlay();
	}
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

void Actor::Destroy()
{
	isToDelete = true;
}


void Actor::AddComponent(Component* _component)
{
	components.insert(_component);
}

void Actor::RemoveComponent(Component* _component)
{
	components.erase(_component);
}


// Level -> SpawnActor(SubClass<Actor>, Transform args...)
// SubclassOf<T> ->  ????
// Actor -> Construct/Deconstruct => Register -> BeginPlay/Update/BeginDestroy