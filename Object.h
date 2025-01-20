#pragma once
#include "CoreMinimal.h"

struct TransformData
{
	Vector2f origin;
	Vector2f position;
	Angle rotation;
	Vector2f scale;
};

class Object
{
protected:
	TransformData transform;

public:
	FORCEINLINE virtual Drawable* GetDrawable() const = 0;

public:
	virtual ~Object() {};

public:
	template <typename T>
	T* Cast(Object* _object)
	{
		if (!IsValid(_object)) return nullptr;
		return dynamic_cast<T>(_object);
	}
};

