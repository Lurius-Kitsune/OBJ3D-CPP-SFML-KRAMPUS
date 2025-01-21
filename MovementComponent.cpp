#include "MovementComponent.h"
#include "Actor.h"

MovementComponent::MovementComponent(Actor* _owner)
	: Component(_owner)
{
	speed = 10.0f;
	direction = Vector2f(1.0f, 0.0f);
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent& _other)
	: Component(_owner)
{
}

void MovementComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	Move(_deltaTime);
}

void MovementComponent::Move(const float _deltaTime)
{
	const Vector2f& _offset = direction * speed * _deltaTime;
	owner->Move(_offset);
}
