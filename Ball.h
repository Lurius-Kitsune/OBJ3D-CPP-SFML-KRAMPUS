#pragma once
#include "MeshActor.h"

class Ball : public MeshActor
{
	bool canMove;
	float mass;
	float gravity;

public:
	FORCEINLINE void SetCanMove(const bool _status)
	{
		canMove = _status;
	}

public:
	Ball(const float _radius);

	virtual void Tick(const float _deltaTime) override;

};