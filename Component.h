#pragma once
#include "Core.h"

class Actor;

class Component : public Core
{
protected:
	Actor* owner;

public:

	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		return true;
	}

	FORCEINLINE Actor* GetOwner()const
	{
		return owner;
	}

public:
	Component(Actor* _actor);
	virtual ~Component() = default;
public:

	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;
};

