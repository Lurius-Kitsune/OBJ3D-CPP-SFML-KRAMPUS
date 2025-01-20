#pragma once
#include "CoreMinimal.h"

struct TransformData
{
	Vector2f origin;
	Vector2f position;
	Angle rotation;
	Vector2f scale;

	TransformData()
	{
		origin = Vector2f(0.0f, 0.0f);
		position = Vector2f(0.0f, 0.0f);
		rotation = Angle();
		scale = Vector2f(1.0f, 1.0f);
	}

	TransformData(const Vector2f& _position,
		const Angle& _rotation, const Vector2f& _scale)
	{
		origin = Vector2f(0.0f, 0.0f);
		position = _position;
		rotation = _rotation;
		scale = _scale;
	}

	TransformData(const Vector2f& _origin, const Vector2f& _position,
		const Angle& _rotation, const Vector2f& _scale)
	{
		origin = _origin;
		position = _position;
		rotation = _rotation;
		scale = _scale;
	}
};