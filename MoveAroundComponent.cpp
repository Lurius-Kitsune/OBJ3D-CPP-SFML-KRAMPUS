#include "MoveAroundComponent.h"

MoveAroundComponent::MoveAroundComponent(MeshActor* _actor, MeshActor* _objectToMoveAround, const float _speed)
	: Component(_actor)
{
	objectToMoveAround = _objectToMoveAround;
	speed = _speed;

	Vector2f _ownerPosition = dynamic_cast<MeshActor*>(owner)->GetShape()->GetPosition();
	Vector2f _objectToMoveAroundPosition = objectToMoveAround->GetShape()->GetPosition();
	radiants = atan2(_ownerPosition.y - _objectToMoveAroundPosition.y, _ownerPosition.x - _objectToMoveAroundPosition.x);
	radius = sqrt(pow((_ownerPosition.x - _objectToMoveAroundPosition.x), 2) + pow((_ownerPosition.y - _objectToMoveAroundPosition.y), 2));
}

void MoveAroundComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}

void MoveAroundComponent::Move(const float _deltaTime)
{
	MeshActor* _owner = dynamic_cast<MeshActor*>(owner);
	Vector2f _ownerPosition = _owner->GetShape()->GetPosition();
	Vector2f _objectToMoveAroundPosition = objectToMoveAround->GetShape()->GetPosition();
	_ownerPosition.x = _objectToMoveAroundPosition.x + radius * cos(radiants);
	_ownerPosition.y = _objectToMoveAroundPosition.y + radius * sin(radiants);

	if (radiants >= M_PI * 2)
	{
		radiants = 0;
	}

	if (radius <= 0)
	{
		owner->BeginDestroy();
	}

	_owner->GetShape()->SetPosition(_ownerPosition);
	radius -= 0.01f * speed;
	radiants += 0.0001f * speed;
}
