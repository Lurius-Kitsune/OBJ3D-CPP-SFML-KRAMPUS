#pragma once
#include "CoreMinimal.h"
#include "TransformData.h"

class ITransformableModifier
{

public:
#pragma region Setter
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) = 0;
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) = 0;
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) = 0;
	FORCEINLINE virtual void SetRotation(const Angle& _angle) = 0;
	FORCEINLINE virtual void SetTransformData(const TransformData& _transformeData)
	{
		SetPosition(_transformeData.origin);
		SetScale(_transformeData.scale);
		SetOrigin(_transformeData.origin);
		SetRotation(_transformeData.rotation);
	}
#pragma endregion

	FORCEINLINE virtual void Move(const Vector2f& _offset) = 0;
	FORCEINLINE virtual void Scale(const Vector2f& _factor) = 0;
	FORCEINLINE virtual void Rotate(const Angle& _angle) = 0;
};

