#include "View.h"

Camera::Camera(Actor* _parent, const Vector2f& _size, const Vector2f& _posCenter, const Actor& _owner) : Actor(_owner)
{
	parent = _parent;
	if (parent)
	{
		SetPosition(parent->GetPosition());
		SetRotation(parent->GetRotation());
	}
}

void Camera::Update()
{
	if (parent)
	{
		SetPosition(parent->GetPosition());
		SetRotation(parent->GetRotation());
	}
}

void Camera::Tick(const float _deltaTime)
{
	Update();
}
