#include "Actor.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "Level.h"

Actor::Actor(Level* _level, const string& _name, const TransformData& _transform)
{
	level = _level;
	name = _name;
	displayName = "Unknown";
	isToDelete = false;
	lifeSpan = 0.0f;
	root = CreateComponent<RootComponent>(_transform);
}

Actor::Actor(const Actor& _actor)
{
	level = _actor.level;
	name = _actor.name;
	displayName = _actor.displayName;
	isToDelete = _actor.isToDelete;
	lifeSpan = _actor.lifeSpan;
	root = CreateComponent<RootComponent>(_actor.root);
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
	id = GetUniqueID();
	//displayName = M_ACTOR.GetAvailableName(name);
	level->GetActorManager().AddActor(this);
}

void Actor::Deconstruct()
{
	level->GetActorManager().RemoveActor(this);
}

void Actor::BeginPlay()
{
	if (lifeSpan > 0.0f)
	{
		new Timer(bind(&Actor::Destroy, this), seconds(lifeSpan), true);
	}

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
	SetToDelete();
}


void Actor::AddComponent(Component* _component)
{
	components.insert(_component);
}

void Actor::RemoveComponent(Component* _component)
{
	components.erase(_component);
}