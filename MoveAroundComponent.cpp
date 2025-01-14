#include "MoveAroundComponent.h"

MoveAroundComponent::MoveAroundComponent(Actor* _actor, Actor* _objectToMoveAround, const float _speed)
{
	owner = _actor;
	objectToMoveAround = _objectToMoveAround;
	speed = _speed;

	Vector2f _ownerPosition = owner->GetShape()->GetPosition();
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
	Vector2f _ownerPosition = owner->GetShape()->GetPosition();
	Vector2f _objectToMoveAroundPosition = objectToMoveAround->GetShape()->GetPosition();
	_ownerPosition.x = _objectToMoveAroundPosition.x + radius * cos(radiants);
	_ownerPosition.y = _objectToMoveAroundPosition.y + radius * sin(radiants);

	if (radiants >= M_PI * 2)
	{
		radiants = 0;
	}

	owner->GetShape()->SetPosition(_ownerPosition);

	radiants += 0.0001f * speed;
}
