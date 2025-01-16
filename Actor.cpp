#include "Actor.h"
#include "ActorManager.h"



Actor::Actor()
{
	Register();
}

Actor::Actor(const float _radius, const string& _path, const size_t& _pointCount, const IntRect& _rect)
{
	shape = new ShapeObject(_radius, _path, _pointCount, _rect);
	Register();
}

Actor::Actor(const Vector2f& _size, const string& _path, const IntRect& _rect)
{
	shape = new ShapeObject(_size, _path, _rect);
	Register();
}

Actor::~Actor()
{
	delete shape;
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

}

void Actor::Register()
{
	Manager(ActorManager).AddActor(this);
}
