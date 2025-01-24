#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	//Mouvement
	bool canMove;
	float moveSpeed;
	Vector2f direction;

	//Bounce
	float bounceDuration;
	Vector2f bounceDirection;


	//fall
	float mass;
	float gravity;

	//
	Vector2f movement;

public:
	FORCEINLINE void SetCanMove(const bool _status)
	{
		canMove = _status;
	}
	FORCEINLINE void ApplyBounce()
	{
		const Vector2f& _normal = Vector2f(0.0f, -1.0f);
		bounceDirection = ComputeRebound(movement, _normal, 0.8f) * gravity * mass;
	}
	FORCEINLINE Vector2f GetMovement()
	{
		return movement;
	}
public:
	Ball(const float _radius);

	virtual void Tick(const float _deltaTime) override;


private:
	
	Vector2f ComputeRebound(const Vector2f _direction, const Vector2f _normal, const float _restitution);

};