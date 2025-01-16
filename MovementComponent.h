#pragma once
#include "Component.h"
#include "MeshActor.h"
class MovementComponent : public Component
{

public:
	MovementComponent(MeshActor* _actor);

public:
	virtual void Tick(const float _deltaTime) override;

	void Move(const float _deltaTime);
};

