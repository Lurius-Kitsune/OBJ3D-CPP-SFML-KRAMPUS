#include "CollisionComponent.h"
#include "MeshActor.h"

CollisionComponent::CollisionComponent(MeshActor* _owner, LayerType _layer, CollisionType _type)
	: Component(_owner)
{
	layer = _layer;
	type = _type;
	mesh = _owner->GetMesh();
}

CollisionComponent::CollisionComponent(Actor* _owner, const CollisionComponent& _collision)
	: Component(_owner)
{
	layer = _collision.layer;
	type = _collision.type;
	mesh = _collision.mesh;
}


void CollisionComponent::OnCollide(const Vector2f& _normal, Vector2f& _velocity)
{
}
