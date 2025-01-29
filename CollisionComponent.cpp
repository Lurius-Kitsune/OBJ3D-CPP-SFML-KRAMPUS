#include "CollisionComponent.h"
#include "MeshActor.h"


CollisionComponent::CollisionComponent(MeshActor* _owner, LayerType _layer, CollisionType _type, const function<void(MeshActor* _meshActor)>& _onCollide)
	: Component(_owner)
{
	layer = _layer;
	type = _type;
	onCollide = _onCollide;
	mesh = _owner->GetComponent<MeshComponent>();
}

CollisionComponent::CollisionComponent(Actor* _owner, const CollisionComponent& _collision)
	: Component(_owner)
{
	layer = _collision.layer;
	type = _collision.type;
	mesh = _collision.mesh;
	onCollide = _collision.onCollide;
}


void CollisionComponent::OnCollide(MeshActor* _meshActor)
{
	onCollide(_meshActor);
}
