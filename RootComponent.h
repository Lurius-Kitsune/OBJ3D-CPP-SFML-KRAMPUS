#pragma once
#include "Component.h"

class RootComponent : public Component, public Transform
{
	
public:
	RootComponent(Actor* _owner);
};