#pragma once
#include "Component.h"
class CameraComponent : public Component
{
	View* view;

public:
	FORCEINLINE View* GetView() const
	{
		return view;
	}
	FORCEINLINE FloatRect GetViewport() const
	{
		return view->getViewport();
	}
	FORCEINLINE void SetViewport(const FloatRect& _viewport)
	{
		view->setViewport(_viewport);
	}

	FORCEINLINE void SetCenter(const Vector2f& _center)
	{
		view->setCenter(_center);
	}
	FORCEINLINE void SetRotation(const Angle& _angle)
	{
		view->setRotation(_angle);
	}
	FORCEINLINE void SetSize(const Vector2f& _size)
	{
		view->setSize(_size);
	}
	FORCEINLINE void SetScissor(const FloatRect& _scissor)
	{
		view->setScissor(_scissor);
	}
	FORCEINLINE void Move(const Vector2f& _offset)
	{
		view->move(_offset);
	}
	FORCEINLINE void Rotate(const Angle& _angle)
	{
		view->rotate(_angle);
	}
	FORCEINLINE void Zoom(const float _factor)
	{
		view->zoom(_factor);
	}


public:
	CameraComponent(Actor* _owner);
	CameraComponent(Actor* _owner, const Vector2f& _start, const Vector2f& _size);
	CameraComponent(Actor* _owner, const FloatRect& _rect);
	CameraComponent(Actor* _owner, const CameraComponent* _other);
	~CameraComponent();
};

