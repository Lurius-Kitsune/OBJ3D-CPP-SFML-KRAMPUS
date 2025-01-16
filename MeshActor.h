#pragma once
#include "Actor.h"
#include "MeshComponent.h"

class MeshActor : public Actor
{
	MeshComponent* mesh;

public:

	FORCEINLINE ShapeObject* GetShape() const
	{
		return mesh->GetShape();
	}

public:
	MeshActor(const float _radius = 0.0f, const string& _path = "",
		const size_t& _pointCount = 30, const IntRect& _rect = IntRect());
	MeshActor(const Vector2f& _size, const string& _path = "", const IntRect& _rect = IntRect());
};

