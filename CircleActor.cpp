#include "CircleActor.h"

CircleActor::CircleActor(Level* _level, const float _radius, const string& _path, const IntRect& _rect,
						 const size_t& _pointCount)
					   : MeshActor(_level, _radius, _pointCount, _path, _rect)
{
	
}