#include "BlackHole.h"
#include "RotateComponent.h"

BlackHole::BlackHole(const float _radius)
	: Actor(_radius, "blackHole")
{
	AddComponent(new RotateComponent(this, 1));
}
