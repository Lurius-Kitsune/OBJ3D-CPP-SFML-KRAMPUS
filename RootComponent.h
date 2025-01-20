#pragma once
#include "Component.h"
#include "TransformData.h"

class RootComponent : public Component
{
	TransformData transform;

public:
	// GET
	FORCEINLINE Vector2f GetOrigin() const
	{
		return transform.origin;
	}
	FORCEINLINE Vector2f GetPosition() const
	{
		return transform.position;
	}
	FORCEINLINE Angle GetRotation() const
	{
		return transform.rotation;
	}
	FORCEINLINE Vector2f GetScale() const
	{
		return transform.scale;
	}
	FORCEINLINE TransformData GetTransform() const
	{
		return transform;
	}
	// SET
	FORCEINLINE virtual void SetOrigin(const Vector2f _origin)
	{
		transform.origin = _origin;
	}
	FORCEINLINE virtual void SetPosition(const Vector2f _position)
	{
		transform.position = _position;
	}
	FORCEINLINE virtual void SetRotation(const Angle _rotation)
	{
		transform.rotation = _rotation;
	}
	FORCEINLINE virtual void SetScale(const Vector2f _scale)
	{
		transform.scale = _scale;
	}
	FORCEINLINE virtual void SetTransform(const TransformData& _transformData)
	{
		transform = _transformData;
	}

	// OVERRIDER
	FORCEINLINE virtual void Move(const Vector2f& _offset)
	{
		transform.position += _offset;
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		transform.rotation += _angle;
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor)
	{
		transform.scale += _factor;
	}

public:
	RootComponent(Actor* _owner);
};

