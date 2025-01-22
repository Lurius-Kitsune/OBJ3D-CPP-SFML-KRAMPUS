#include "Animation.h"

Animation::Animation(const string& _name, ShapeObject* _object, const AnimationData& _data)
{
	currentIndex = 0;
	name = _name;
	data = _data;
	shape = _object;
	timer = nullptr;
}
