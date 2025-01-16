#include "RotateComponent.h"

RotateComponent::RotateComponent(MeshActor* _actor, const float _speed)
	: Component(_actor)
{
	speed = _speed;
}

void RotateComponent::Tick(const float _deltaTime)
{
	Rotate(_deltaTime);
}

void RotateComponent::Rotate(const float _deltaTime)
{
	MeshActor* _owner = dynamic_cast<MeshActor*>(owner);
	_owner->GetShape()->Rotate(degrees(0.1f * speed));
}
