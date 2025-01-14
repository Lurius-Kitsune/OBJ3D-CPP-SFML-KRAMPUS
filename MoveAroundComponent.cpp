#include "MoveAroundComponent.h"

MoveAroundComponent::MoveAroundComponent(Actor* _actor, Actor* _objectToMoveAround, const float _speed)
{
	owner = _actor;
	objectToMoveAround = _objectToMoveAround;
	speed = speed;

	Vector2f _ownerPosition = owner->GetShape()->GetPosition();
	Vector2f _objectToMoveAroundPosition = objectToMoveAround->GetShape()->GetPosition();
	radiants = atan2(_ownerPosition.x - _objectToMoveAroundPosition.x, _ownerPosition.y - _objectToMoveAroundPosition.y);
	radius = sqrt(pow((_ownerPosition.x - _objectToMoveAroundPosition.x), 2) + pow((_ownerPosition.y - _objectToMoveAroundPosition.y), 2));
}

void MoveAroundComponent::Tick(const float _deltaTime)
{
	Move(_deltaTime);
}

void MoveAroundComponent::Move(const float _deltaTime)
{
	Vector2f _ownerPosition = owner->GetShape()->GetPosition();

	_ownerPosition.x = _ownerPosition.x + radius * cos(radiants);
	_ownerPosition.y = _ownerPosition.y + radius * sin(radiants);

	if (radiants >= M_PI * 2)
	{
		radiants = 0;
	}

	owner->GetShape()->SetPosition(_ownerPosition);

	radiants += 0.000000001f;
}
