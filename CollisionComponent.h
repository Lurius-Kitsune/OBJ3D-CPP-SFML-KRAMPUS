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
	MeshComponent* mesh;
	function<void(MeshActor* _meshActor)> onCollide;

public:
	FORCEINLINE CollisionType GetCollisionType() const
	{
		return type;
	}
	FORCEINLINE void SetCollisionType(CollisionType _type)
	{
		type = _type;
	}
	FORCEINLINE FloatRect GetGlobalBound() const
	{
		return mesh->GetGlobalBound();
	}

public:
	CollisionComponent(MeshActor* _owner, LayerType _layer, CollisionType _type,  const function<void(MeshActor* _meshActor)>& _onCollide = nullptr);
	CollisionComponent(Actor* _owner, const CollisionComponent& _collision);

public:
	void OnCollide(MeshActor* _meshActor);
};