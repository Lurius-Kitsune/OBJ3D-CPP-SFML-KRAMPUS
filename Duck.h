#pragma once
#include "MeshActor.h"
#include "MovementComponent.h"
//#include "AnimationComponent.h"

class Duck : public MeshActor
{
	float lifeSpan;
	MovementComponent* movement;
//	AnimationComponent* animation;
public:
	Duck(const Vector2f& _size, const string& _path = "", const IntRect& _rect = {});
	Duck(const Duck& _duck);

protected:
	virtual void BeginPlay() override;

};

