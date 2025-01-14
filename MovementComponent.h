#pragma once
#include "Component.h"
#include "Actor.h"
class MovementComponent : public Component
{
	Actor* owner;

public:
	MovementComponent(Actor* _actor);

public:
	virtual void Tick(const float _deltaTime) override;

	void Move(const float _deltaTime);
};

