#pragma once
#include "CoreMinimal.h"
#include "ITransformableModifier.h"

class Object : public ITransformableModifier
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
public:
	virtual ~Object() {};

};

