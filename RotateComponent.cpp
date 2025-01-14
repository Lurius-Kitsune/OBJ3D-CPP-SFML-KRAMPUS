#include "RotateComponent.h"

RotateComponent::RotateComponent(Actor* _actor, const float _speed)
{
	speed = _speed;
	owner = _actor;
}

void RotateComponent::Tick(const float _deltaTime)
{
	Rotate(_deltaTime);
}

void RotateComponent::Rotate(const float _deltaTime)
{
	owner->GetShape()->Rotate(degrees(0.1f * speed));
}
