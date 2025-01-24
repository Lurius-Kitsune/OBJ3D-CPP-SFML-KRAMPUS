#include "Ball.h"

Ball::Ball(const float _radius) : MeshActor(_radius)
{
	//Mouvement
	canMove = true;
	moveSpeed = 5.0f;
	direction = Vector2f();

	//Bounce
	elasticity = 0.0f;
	bounceDirection = Vector2f();

	//Fall
	mass = 20.0f;
	gravity = 9.81f;
}


void Ball::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	if (canMove)
	{
		//Direction
		const Vector2f& _directionOffset = direction * moveSpeed * 100.0f;

		// Fall
		const Vector2f& _downVector = Vector2f(0.0f, 1.0f);
		const Vector2f& _fallOffset = _downVector * gravity * mass;

		//Bounce
		const Vector2f& _normal = Vector2f(0.0f, 1.0f);
		const Vector2f& _bounceOffset = ComputeRebound(_fallOffset, _normal, 0.8f);

		//Result
		const Vector2f& _offset = (_directionOffset + _fallOffset + _bounceOffset) * _deltaTime;
		Move(_offset);
	}
}


Vector2f Ball::ComputeRebound(const Vector2f _direction,const Vector2f _normal, const float _restitution)
{
	Vector2f _normalizedNormal = _normal.normalized();
	float _dotProduct = _direction.dot(_normalizedNormal);
	return _direction - _normalizedNormal * ((1 + _restitution) * _dotProduct);
}
