#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(Actor* _owner) : Component(_owner)
{
}

AnimationComponent::AnimationComponent(Actor* _owner, const AnimationComponent& _other)
	:Component(_owner)
{
}

void AnimationComponent::Tick(const float _deltaTime)
{
}
