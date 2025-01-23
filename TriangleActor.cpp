#include "TriangleActor.h"

TriangleActor::TriangleActor(const float _radius, const string& _path, const float _lifespan, const IntRect& _rect)
						   : MeshActor(_radius, 3, _path, _lifespan, _rect)
{

}