#pragma once
#include "MeshActor.h"

class Bird : public MeshActor
{


public:
	Bird();
	Bird(const Bird& _other);

public:
	virtual void BeginPlay() override;
	virtual void Update(const float _deltaTime) override;
};