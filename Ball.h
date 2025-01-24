#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	bool canMove;
	float moveSpeed;
	float mass;
	float gravity;
	Vector2f direction;

public:
	FORCEINLINE void SetCanMove(const bool _status)
	{
		canMove = _status;
	}

	FORCEINLINE void SetDirection(const Vector2f& _direction)
	{
		direction = _direction;
	}

public:
	Ball(const float _radius);

	virtual void Tick(const float _deltaTime) override;

};