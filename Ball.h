#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	//Mouvement
	bool canMove;
	float moveSpeed;
	Vector2f direction;

	//bounce
	float elasticity;
	Vector2f bounceDirection;

	//fall
	float mass;
	float gravity;

public:
	FORCEINLINE void SetCanMove(const bool _status)
	{
		canMove = _status;
	}

	FORCEINLINE void SetDirection(const Vector2f& _direction)
	{
		bounceDirection = _direction;
	}

public:
	Ball(const float _radius);

	virtual void Tick(const float _deltaTime) override;


private:
	Vector2f ComputeRebound(const Vector2f _direction, const Vector2f _normal, const float _restitution);

};