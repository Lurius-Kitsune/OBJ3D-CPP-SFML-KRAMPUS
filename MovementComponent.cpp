#include "MovementComponent.h"

MovementComponent::MovementComponent(MeshActor* _actor)
	: Component(_actor)
{
}

void MovementComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}

void MovementComponent::Move(const float _deltaTime)
{
	MeshActor* _owner = dynamic_cast<MeshActor*>(owner);
	_owner->GetShape()->Move(Vector2f(0.05f, 0.05f) * _deltaTime * 1000.0f);
	_owner->GetShape()->Rotate(radians(0.001f * _deltaTime * 1000.0f));
	
	const Vector2f& _scale = _owner->GetShape()->GetDrawable()->getScale();
	if (_scale.x <= 0.f)
	{
		_owner->BeginDestroy();
		return;
	}
	_owner->GetShape()->SetScale(_scale - (Vector2f(0.0001f, 0.0001f) * _deltaTime * 1000.0f));
}
