#include "Star.h"
#include "RotateComponent.h"
Star::Star(const float _radius)
	: Actor(_radius, "star", 5)
{
	AddComponent(new RotateComponent(this, 1));
	GetShape()->GetDrawable()->setFillColor(Color::Yellow);
}
