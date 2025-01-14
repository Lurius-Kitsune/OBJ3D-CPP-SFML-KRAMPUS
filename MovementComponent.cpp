#include "MovementComponent.h"

MovementComponent::MovementComponent(Actor* _actor)
{
	owner = _actor;
}

void MovementComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}

void MovementComponent::Move(const float _deltaTime)
{
	owner->GetShape()->Move({ 0.05f, 0.05f });
	owner->GetShape()->Rotate(radians(0.001f));
	
	const Vector2f& _scale = owner->GetShape()->GetDrawable()->getScale();
	if (_scale.x <= 0.f)
	{
		owner->BeginDestroy();
		return;
	}
	owner->GetShape()->SetScale({ _scale.x - 0.0001f, _scale.y - 0.0001f});
}
