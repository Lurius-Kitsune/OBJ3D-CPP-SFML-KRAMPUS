#pragma once
#include "Object.h"

class ShapeObject : public Object
{
	Shape* shape;
	Texture texture;

public:
	FORCEINLINE virtual Shape* GetDrawable() const override
	{
		return shape;
	}

	FORCEINLINE Texture& GetTexture() 
	{
		return texture;
	}

	#pragma region Setter
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		shape->setOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		shape->setPosition(_position);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		shape->setScale(_scale);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _angle) override
	{
		shape->setRotation(_angle);
	}
	FORCEINLINE virtual void SetTransformData(const TransformData& _transformeData)override
	{
		Super::SetTransformData(_transformeData);
		shape->setOrigin(_transformeData.origin);
		shape->setPosition(_transformeData.position);
		shape->setScale(_transformeData.scale);
		shape->setRotation(_transformeData.rotation);
	}
	#pragma endregion

	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		shape->move(_offset);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		shape->scale(_factor);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		shape->rotate(_angle);
	}

public:
	ShapeObject(const float _radius = 0.0f, const string& _path = "",
		const size_t& _pointCount = 30, const IntRect& _rect = IntRect());
	ShapeObject(const Vector2f& _size, const string& _path = "", const IntRect& _rect = IntRect());
	~ShapeObject();

public:

};

