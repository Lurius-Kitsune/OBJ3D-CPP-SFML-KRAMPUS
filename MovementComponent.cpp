#include "MovementComponent.h"
#include "Actor.h"

MovementComponent::MovementComponent(Actor* _owner) : Component(_owner)
{
	rotateSpeed = 100.0f;
	speed = 30.0f;
	direction = Vector2f(1.0f, 0.0f);
}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent* _other) : Component(_owner)
{
	speed = _other->speed;
	//rotateSpeed = _other->rotateSpeed;
	direction = _other->direction;
}


void MovementComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);

	//Move(_deltaTime);
	RotateAround(_deltaTime);
}


void MovementComponent::Move(const float _deltaTime)
{
	const Vector2f& _offset = direction * speed * _deltaTime;
	owner->Move(_offset);
}

void MovementComponent::RotateAround(const float _deltaTime)
{
	if (!target) return;
	// Calcule trigonometrique de rotation autour d'un point
	const Vector2f& _center = target->GetPosition();
	const Vector2f& _relativePos = owner->GetPosition() - _center;
	const float _radAngle = DegToRad(rotateSpeed * _deltaTime);

	const float _newPosX = _relativePos.x * cos(_radAngle) - _relativePos.y * sin(_radAngle);
	const float _newPosY = _relativePos.x * sin(_radAngle) + _relativePos.y * cos(_radAngle);
	const Vector2f& _newPos = _center + Vector2f(_newPosX, _newPosY);

	owner->SetPosition(_newPos);
}
