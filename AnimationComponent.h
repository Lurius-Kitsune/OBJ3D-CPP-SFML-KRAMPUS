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
	FORCEINLINE void SetCurrentAnimation(const string& _name)
	{
		current = allAnimations[_name];
	}

public:
	AnimationComponent(Actor* _owner);
	AnimationComponent(Actor* _owner, const AnimationComponent& _other);
	~AnimationComponent();
public:
	void AddAnimation(Animation* _animation);
	void AddAnimation(const vector<Animation*>& _animations);
protected:
	virtual void Tick(const float _deltaTime) override;

private:
};

