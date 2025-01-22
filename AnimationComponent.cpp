#include "AnimationComponent.h"

AnimationComponent::AnimationComponent(Actor* _owner) : Component(_owner)
{
	current = nullptr;
	allAnimations = map<string, Animation*>();
}

AnimationComponent::AnimationComponent(Actor* _owner, const AnimationComponent& _other)
	:Component(_owner)
{	
	for (pair<string, Animation*> _animation : _other.allAnimations)
	{
		allAnimations[_animation.first] = new Animation(*_animation.second);
	}

	current = allAnimations[_other.current->GetName()];
}

AnimationComponent::~AnimationComponent()
{
	for (pair<string, Animation*> _animation : allAnimations)
	{
		delete _animation.second;
	}
}

void AnimationComponent::AddAnimation(Animation* _animation)
{
	const string& _animationName = _animation->GetName();
	if (allAnimations.contains(_animationName)) return;
	allAnimations.insert({ _animationName, _animation });
}

void AnimationComponent::AddAnimation(const vector<Animation*>& _animations)
{
	for (Animation* _animation : _animations)
	{
		AddAnimation(_animation);
	}
}

void AnimationComponent::Tick(const float _deltaTime)
{
}
