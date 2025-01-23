#include "TriangleActor.h"

TriangleActor::TriangleActor(const string& _name, const float _radius, const string& _path, const IntRect& _rect)
						   : MeshActor(_name, _radius, 3, _path, _rect)
{

}