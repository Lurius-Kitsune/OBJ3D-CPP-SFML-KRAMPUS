#pragma once
#include "Component.h"
#include "ITransformableViewer.h"
#include "ITransformableModifier.h"

class RootComponent : public Component, public ITransformableViewer
{
	TransformData root;
public:
	#pragma region Getter
	FORCEINLINE virtual TransformData GetTransform() const override
	{
		return root;
	}
	FORCEINLINE  Vector2f GetOrigin() const override
	{
		return root.origin;
	}
	FORCEINLINE  Vector2f GetPosition() const override
	{
		return root.position;
	}
	FORCEINLINE  Vector2f GetScale() const override
	{
		return root.scale;
	}
	FORCEINLINE  Angle GetRotation() const override
	{
		return root.rotation;
	}
	#pragma endregion

	#pragma region Setter
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin)
	{
		root.origin = _origin;
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position)
	{
		root.position = _position;
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale)
	{
		root.scale = _scale;
	}
	FORCEINLINE virtual void SetRotation(const Angle& _angle)
	{
		root.rotation = _angle;
	}
	FORCEINLINE virtual void SetTransformData(const TransformData& _transformeData)
	{
		root = _transformeData;
	}
	#pragma endregion

	FORCEINLINE virtual void Move(const Vector2f& _offset)
	{
		root.position += _offset;
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor)
	{
		root.scale += _factor;
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle)
	{
		root.rotation += _angle;
	}
public:
	RootComponent(Actor* _owner);
};

