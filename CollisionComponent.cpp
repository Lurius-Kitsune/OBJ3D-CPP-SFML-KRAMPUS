#include "CollisionComponent.h"
#include "MeshActor.h"

CollisionComponent::CollisionComponent(MeshActor* _owner, map<LayerType, CollisionType> _collisionResponse, const function<void(MeshActor* _meshActor)>& _onCollide)
	: Component(_owner)
{
	collisionResponse = _collisionResponse;
	onCollide = _onCollide;
}

CollisionComponent::CollisionComponent(Actor* _owner, const CollisionComponent& _collision)
	: Component(_owner)
{
	generateHitEvent = _collision.generateHitEvent;
	collisionResponse = _collision.collisionResponse;
	type = _collision.type;
	mesh = _collision.mesh;
	onCollide = _collision.onCollide;
	overlapEvent = _collision.overlapEvent;
}


void CollisionComponent::OnCollide(MeshActor* _collider)
{
	if (generateHitEvent)
	{
		if (onCollide)
		{
			onCollide(_collider);
			// Note : _owner->OnCollide(_collider); ?
		}
	}

	CollisionComponent* _colliderCollision = _collider->GetComponent<CollisionComponent>();

	if(_colliderCollision)
	{
		if (collisionResponse[_colliderCollision->GetCollisionType()] == CT_BLOCK)
		{
			// Overlap -> Fait passer � travers et appelle un overlapEvent si mit :
			if(overlapEvent)
			{
				overlapEvent(_collider);
			}
			// Note : _owner->OnOverlap(_collider); ?
		}
		else if (collisionResponse[_colliderCollision->GetCollisionType()] == CT_BLOCK)
		{
			// Bloque -> emp�che le mouvement � travers l'objet
		}
		else if (collisionResponse[_colliderCollision->GetCollisionType()] == CT_NONE)
		{
			// Passe � travers
		}
	}
}
