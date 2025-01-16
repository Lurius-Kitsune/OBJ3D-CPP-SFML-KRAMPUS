#pragma once
#include "Component.h"
#include "MeshActor.h"
class MoveAroundComponent : public Component
{
	MeshActor* objectToMoveAround;
	int speed;
	float radiants;
	float radius;

public: 
	MoveAroundComponent(MeshActor* _actor, MeshActor* _objectToMoveAround, const float _speed = 1.0f);

public:
	virtual void Tick(const float _deltaTime) override;

	void Move(const float _deltaTime);

};

