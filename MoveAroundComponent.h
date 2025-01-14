#pragma once
#include "Component.h"
#include "Actor.h"
class MoveAroundComponent : public Component
{
	Actor* owner;
	Actor* objectToMoveAround;
	int speed;
	float radiants;
	float radius;

public:
	MoveAroundComponent(Actor* _actor, Actor* _objectToMoveAround, const float _speed = 1.0f);

public:
	virtual void Tick(const float _deltaTime) override;

	void Move(const float _deltaTime);

};

