#pragma once
#include "Actor.h"
#include "ShapeObject.h"
#include "MeshComponent.h"

class MeshActor : public Actor
{
	MeshComponent* mesh;
	u_int renderMeshToken;

public:
	FORCEINLINE virtual void Move(const Vector2f& _offset) const override
	{
		Super::Move(_offset);
		mesh->GetShape()->Move(_offset);
	}

	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		return Super::IsValid(_core) && mesh;
	}

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
	virtual~MeshActor();
private:
	void RenderMesh(RenderWindow& _window);
};

