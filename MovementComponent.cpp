#include "MovementComponent.h"
#include "Actor.h"
#include "Utilities.h"
#include "TimerManager.h"

MovementComponent::MovementComponent(Actor* _owner) : Component(_owner)
{
	rotateSpeed = 100.0f;
	speed = 30.0f;
	direction = Vector2f(1.0f, 0.0f);
	windDirection = { 5.f, 5.f };

	new Timer([&]()
		{
			ChangeWindDirection();
		},
		seconds(2.0f),
		true,
		true
	);

}

MovementComponent::MovementComponent(Actor* _owner, const MovementComponent* _other) : Component(_owner)
{
	speed = _other->speed;
	//rotateSpeed = _other->rotateSpeed;
	direction = _other->direction;
}

void MovementComponent::ChangeWindDirection()
{
	windDirection = { GetRandomNumberInRange(-10.f, 10.f), GetRandomNumberInRange(-10.f, 10.f) };
}


void MovementComponent::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	cout << windDirection.x << " / " << windDirection.y << endl;
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
	const float _radAngle = DegToRad(rotateSpeed * _deltaTime * 0.0000001f);

	const float _newPosX = _relativePos.x * cos(_radAngle) - _relativePos.y * sin(_radAngle);
	const float _newPosY = _relativePos.x * sin(_radAngle) + _relativePos.y * cos(_radAngle);
	const Vector2f& _newPos = _center + Vector2f(_newPosX, _newPosY);

	owner->SetPosition(_newPos + Vector2f(windDirection.x, windDirection.y));

	Vector2f _velocity(_newPosX - _relativePos.x, _newPosY - _relativePos.y);

	const float _newRotation = RadToDeg(atan2(_velocity.y, _velocity.x));

	owner->SetRotation(degrees(_newRotation));
}
