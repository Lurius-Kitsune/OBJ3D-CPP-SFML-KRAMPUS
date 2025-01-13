#pragma once
#include "Core.h"
class Component : public Core
{
public:

	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;
};

