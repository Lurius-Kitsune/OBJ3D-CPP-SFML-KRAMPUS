#pragma once
#include "Actor.h"
class Camera : public Actor
{
	View* view;

public:

#pragma region Transformable

#pragma region Viewer

	FORCEINLINE virtual Vector2f GetOrigin() const override
	{
		return view->getCenter();
	}
	FORCEINLINE virtual Vector2f GetPosition() const override
	{
		return view->getCenter();
	}
	FORCEINLINE virtual Angle GetRotation() const override
	{
		return view->getRotation();
	}
	FORCEINLINE virtual Vector2f GetScale() const override
	{
		return view->getSize();
	}

#pragma endregion

#pragma region Modifier

	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		Super::SetPosition(_position);
		view->setCenter(_position);
	}

	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		Super::SetRotation(_rotation);
		view->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		Super::SetScale(_scale);
		view->setSize(_scale);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		view->move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		Super::Rotate(_angle);
		view->rotate(_angle);
	}

	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		Super::Scale(_factor);
		view->zoom(_factor.x);
	}

#pragma endregion

#pragma endregion

public:
	Camera(const Vector2f& _centerPosition, const Vector2f& _size);
	Camera(const FloatRect& _viewRect);
	~Camera()
};

