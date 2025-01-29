#pragma once
#include "Component.h"
#include "MeshComponent.h"

class MeshActor;

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
	bool generateHitEvent;
	LayerType type;
	map<LayerType, CollisionType> collisionResponse;
	MeshComponent* mesh;

	// Todo -> put it on MeshActor (I think?)
	function<void(MeshActor* _meshActor)> onCollide;
	function<void(MeshActor* _meshActor)> overlapEvent;

public:
	FORCEINLINE LayerType GetCollisionType() const
	{
		return type;
	}
	FORCEINLINE void SetCollisionType(LayerType _type)
	{
		type = _type;
	}
	FORCEINLINE FloatRect GetGlobalBound() const
	{
		return mesh->GetGlobalBound();
	}

public:
	CollisionComponent(MeshActor* _owner, map<LayerType, CollisionType> _collisionResponse,  const function<void(MeshActor* _meshActor)>& _onCollide = nullptr);
	CollisionComponent(Actor* _owner, const CollisionComponent& _collision);

public:
	void OnCollide(MeshActor* _collider);
};