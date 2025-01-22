#pragma once
#include "Component.h"
#include "Animation.h"
class AnimationComponent : public Component
{
	// AnimationPose -> only
	// StateMachine -> AutoSwitch
	Animation* current;
	map<string, Animation*> allAnimations;

public:
	AnimationComponent(Actor* _owner);
	AnimationComponent(Actor* _owner, const AnimationComponent& _other);

protected:
	virtual void Tick(const float _deltaTime) override;

private:
};

