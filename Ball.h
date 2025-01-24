#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	float mass;
	float gravity;

public:
	Ball(const float _radius);

	virtual void Tick(const float _deltaTime) override;
};

