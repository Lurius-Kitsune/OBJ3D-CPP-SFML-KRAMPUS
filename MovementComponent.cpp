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
	_owner->GetShape()->Move({ 0.05f, 0.05f });
	_owner->GetShape()->Rotate(radians(0.001f));
	
	const Vector2f& _scale = _owner->GetShape()->GetDrawable()->getScale();
	if (_scale.x <= 0.f)
	{
		_owner->BeginDestroy();
		return;
	}
	_owner->GetShape()->SetScale({ _scale.x - 0.0001f, _scale.y - 0.0001f});
}
