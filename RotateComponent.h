#pragma once
#include "Component.h"
#include "Actor.h"
class RotateComponent : public Component
{
	float speed;
	Actor* owner;

public:
	RotateComponent(Actor* _actor, const float _speed = 1.0f);

public:
	virtual void Tick(const float _deltaTime) override;

	void Rotate(const float _deltaTime);

};

