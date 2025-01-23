#include "CircleActor.h"

CircleActor::CircleActor(const string& _name, const float _radius, const string& _path, const IntRect& _rect,
						 const size_t& _pointCount)
					   : MeshActor(_name, _radius, _pointCount, _path, _rect)
{
	
}