#pragma once
#include "Component.h"

class MeshActor;
class Actor;

enum CollisionType
{
	CT_NONE,
	CT_OVERLAP,
	CT_BLOCK
};

enum LayerType
{
	LT_STATIC,
	LT_DYNAMIC,

	// =========== \\


};

class CollisionComponent : public Component
{
	LayerType layer;
	CollisionType type;

public:
	FORCEINLINE CollisionType GetCollisionType() const
	{
		return type;
	}
	FORCEINLINE void SetCollisionType(CollisionType _type)
	{
		type = _type;
	}
	FORCEINLINE FloatRect GetGlobalBound()
	{
		return Cast<MeshActor>(owner)->GetMesh()->GetGlobalBound();
	}

public:
	CollisionComponent(MeshActor* _owner, LayerType _layer, CollisionType _type);

public:
	void OnCollide(const Vector2f& _normal, Vector2f& _velocity);
};