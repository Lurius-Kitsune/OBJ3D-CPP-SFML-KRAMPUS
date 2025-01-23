#pragma once
#include "Actor.h"
#include "CameraComponent.h"
class CameraActor : public Actor
{
	CameraComponent* camera;
	Actor* target;

public:
	FORCEINLINE void SetViewport(const FloatRect& _viewport)
	{
		camera->SetViewport(_viewport);
	}

	FORCEINLINE void SetPosition(const Vector2f& _center) override
	{
		Super::SetPosition(_center);
		camera->SetCenter(_center);
	}
	FORCEINLINE void SetRotation(const Angle& _angle) override
	{
		Super::SetRotation(_angle);
		camera->SetRotation(_angle);
	}
	FORCEINLINE void SetScale(const Vector2f& _size) override
	{
		Super::SetScale(_size);
		camera->SetSize(_size);
	}
	FORCEINLINE void SetScissor(const FloatRect& _scissor)
	{
		camera->SetScissor(_scissor);
	}
	FORCEINLINE void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		camera->Move(_offset);
	}
	FORCEINLINE void Rotate(const Angle& _angle) override
	{
		Super::Rotate(_angle);
		camera->Rotate(_angle);
	}
	FORCEINLINE void Zoom(const float _factor)
	{
		camera->Zoom(_factor);
	}
	FORCEINLINE void SetTarget(Actor* _target)
	{
		target = _target;
	}
	FORCEINLINE View* GetView() const
	{
		return camera->GetView();
	}
public:
	CameraActor();
	CameraActor(const Vector2f& _start, const Vector2f& _size);
	CameraActor(const FloatRect& _rect);
	CameraActor(const CameraActor& _other);
	virtual ~CameraActor();

public:
	virtual void Construct() override;
	virtual void Deconstruct() override;

	virtual void Tick(const float _deltaTime) override;
};

