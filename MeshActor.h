#pragma once
#include "Actor.h"
#include "MeshComponent.h"

class MeshActor : public Actor
{
	MeshComponent* mesh;

public:
	FORCEINLINE MeshComponent* GetMesh() const
	{
		return mesh;
	}

	FORCEINLINE ShapeObject* GetShape() const
	{
		return mesh->GetShape();
	}

public:
	MeshActor(const float _radius, const size_t& _pointCount,
		const string& _path, const IntRect& _rect);
	MeshActor(const Vector2f& _size, const string& _path, const IntRect& _rect);
};

