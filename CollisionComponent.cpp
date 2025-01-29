#include "CollisionComponent.h"
#include "MeshActor.h"

CollisionComponent::CollisionComponent(MeshActor* _owner, map<pair<LayerType, CollisionType>, bool> _collisionResponse, const function<void(MeshActor* _meshActor)>& _onCollide)
	: Component(_owner)
{
	collisionResponse = _collisionResponse;
	onCollide = _onCollide;
}

CollisionComponent::CollisionComponent(Actor* _owner, const CollisionComponent& _collision)
	: Component(_owner)
{
	layer = _collision.layer;
	type = _collision.type;
	mesh = _collision.mesh;
	onCollide = _collision.onCollide;
}


void CollisionComponent::OnCollide(MeshActor* _collider)
{
	if (generateHitEvent)
	{
		if (onCollide)
		{
			onCollide(_collider);
		}
	}

	CollisionComponent* _colliderCollision = _collider->GetComponent<CollisionComponent>();

	if(_colliderCollision)
	{
		if (collisionResponse[_colliderCollision->GetCollisionType()] == CT_BLOCK)
		{
			// Overlap -> Fait passer à travers et appelle un overlapEvent si mit :
			if(overlapEvent)
			{
				overlapEvent(_collider);
			}
		}
		else if (collisionResponse[_colliderCollision->GetCollisionType()] == CT_BLOCK)
		{
			// Bloque -> empêche le mouvement à travers l'objet
		}
		else if (collisionResponse[_colliderCollision->GetCollisionType()] == CT_NONE)
		{
			// Passe à travers
		}
	}
}
