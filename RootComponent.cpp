#include "RootComponent.h"


RootComponent::RootComponent(Actor* _owner)
	: Component(_owner)
{
}
RootComponent::RootComponent(const RootComponent& _other)
{
	root = _other.root;
}