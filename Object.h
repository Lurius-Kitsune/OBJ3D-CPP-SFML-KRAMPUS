#pragma once
#include "CoreMinimal.h"
#include "TransformData.h"

class Object
{
protected:

public:
	FORCEINLINE virtual Drawable* GetDrawable() const = 0;


//#pragma region Getter
//	FORCEINLINE virtual TransformData GetTransform() const = 0;
//	FORCEINLINE virtual Vector2f GetOrigin() const = 0;
//	FORCEINLINE virtual Vector2f GetPosition() const = 0;
//	FORCEINLINE virtual Vector2f GetScale() const = 0;
//	FORCEINLINE virtual Angle GetRotation() const = 0;
//#pragma endregion

#pragma region Setter
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) = 0;
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) = 0;
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) = 0;
	FORCEINLINE virtual void SetRotation(const Angle& _angle) = 0;
	FORCEINLINE virtual void SetTransformData(const TransformData& _transformeData) = 0;
#pragma endregion

	FORCEINLINE virtual void Move(const Vector2f& _offset) = 0;
	FORCEINLINE virtual void Scale(const Vector2f& _factor) = 0;
	FORCEINLINE virtual void Rotate(const Angle& _angle) = 0;
public:
	virtual ~Object() {};

};

