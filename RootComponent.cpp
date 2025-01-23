#include "RootComponent.h"

RootComponent::RootComponent(Actor* _owner) : Component(_owner)
{
	transform = TransformData();
}

RootComponent::RootComponent(Actor* _owner, const TransformData& _transformData)
	: Component(_owner)
{
	transform = _transformData;
}

RootComponent::RootComponent(Actor* _owner, const RootComponent* _other) : Component(_owner)
{
	transform = _other->transform;
}