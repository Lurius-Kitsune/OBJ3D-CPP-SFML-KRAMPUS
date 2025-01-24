#include "Ball.h"

Ball::Ball(const float _radius) : MeshActor(_radius)
{
	canMove = true;
	moveSpeed = 10.0f;
	mass = 20.0f;
	gravity = 9.81f;
	direction = Vector2f();
}


void Ball::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	if (canMove)
	{
		const Vector2f& _directionOffset = direction * moveSpeed * _deltaTime;

		// Fall
		const Vector2f& _downVector = Vector2f(0.0f, 1.0f);
		const Vector2f& _fallOffset = _downVector * gravity * mass * _deltaTime;

		const Vector2f& _offset = _directionOffset + _fallOffset;
		Move(_offset);
	}
}