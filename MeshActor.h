#pragma once
#include "Actor.h"
#include "ShapeObject.h"
#include "MeshComponent.h"

class MeshActor : public Actor
{
	MeshComponent* mesh;
	u_int renderMeshToken;

public:
#pragma region Modifier
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		Super::SetOrigin(_origin);
		mesh->GetShape()->SetOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		Super::SetPosition(_position);
		mesh->GetShape()->SetPosition(_position);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		Super::SetScale(_scale);
		mesh->GetShape()->SetScale(_scale);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _angle) override
	{
		Super::SetRotation(_angle);
		mesh->GetShape()->SetRotation(_angle);
	}

	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		Super::Move(_offset);
		mesh->GetShape()->Move(_offset);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		Super::Scale(_factor);
		mesh->GetShape()->Scale(_factor);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		Super::Rotate(_angle);
		mesh->GetShape()->Rotate(_angle);
	}
#pragma endregion

	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		return Super::IsValid(_core) && mesh;
	}

	FORCEINLINE MeshComponent* GetMesh() const
	{
		return mesh;
	}


public:
	MeshActor(const float _radius, const size_t& _pointCount,
		const string& _path, const IntRect& _rect);
	MeshActor(const Vector2f& _size, const string& _path, const IntRect& _rect);
	MeshActor(MeshActor& _actor);
	virtual~MeshActor();

public:
	virtual void Deconstruct() override;
	void RenderMesh(RenderWindow& _window);
};

