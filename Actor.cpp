#include "Actor.h"

Actor::Actor()
{
}

Actor::~Actor()
{
	for (Component* _component : components)
	{
		delete _component;
	}
}

void Actor::BeginPlay()
{
}

void Actor::Tick(const float _deltaTime)
{

}

void Actor::BeginDestroy()
{
}
