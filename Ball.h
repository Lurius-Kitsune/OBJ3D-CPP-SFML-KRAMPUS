#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	// Movement
	bool canMove;
	float moveSpeed;
	Vector2f direction;

	// Bounce
	float bounceDuration;
	Vector2f bounceDirection;

	// Fall
	float mass;
	float gravity;
	Vector2f fallMovement;

public:
	FORCEINLINE void SetCanMove(const bool _status)
	{
		canMove = _status;
	}
	FORCEINLINE void ApplyBounce()
	{
		const Vector2f& _normal = Vector2f(0.0f, -1.0f);
		bounceDirection = ComputeRebound(fallMovement, _normal, 0.8f)/* * gravity * mass*/;
		fallMovement = Vector2f();
	}
	FORCEINLINE Vector2f GetMovement() const
	{
		return fallMovement;
	}

public:
	Ball(const float _radius);

	virtual void Tick(const float _deltaTime) override;

private:
	Vector2f ComputeRebound(const Vector2f& _direction, const Vector2f& _normal, const float _restitution);
};