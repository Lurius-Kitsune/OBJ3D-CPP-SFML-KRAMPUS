#include "CollisionComponent.h"
#include "MeshActor.h"

CollisionComponent::CollisionComponent(MeshActor* _owner, LayerType _layer, CollisionType _type)
	: Component(_owner)
{
	layer = _layer;
	type = _type;
}

void CollisionComponent::OnCollide(const Vector2f& _normal, Vector2f& _velocity)
{
}
