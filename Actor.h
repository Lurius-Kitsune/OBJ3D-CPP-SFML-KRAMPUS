#pragma once
#include "Core.h"
#include "ShapeObject.h"
#include "Component.h"

class Actor : public Core
{
	ShapeObject* shape;
	set<Component*> components;

public:
	Actor();
	~Actor();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;
};

