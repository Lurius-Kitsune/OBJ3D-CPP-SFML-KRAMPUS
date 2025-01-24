#include "Ball.h"

Ball::Ball(const float _radius) : MeshActor (_radius)
{
	mass = 5.0f;
	gravity = 9.81f;
}

void Ball::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	//Fall
	const Vector2f& _downVector = Vector2f(0.0f, 1.0f);
	const Vector2f& _offset = _downVector * gravity  * mass;

	Move();
}

