#include "CircleActor.h"

CircleActor::CircleActor(const float _radius, const string& _path, const float _lifespan, const IntRect& _rect,
						 const size_t& _pointCount)
					   : MeshActor(_radius, _pointCount, _path, _lifespan, _rect)
{
	
}