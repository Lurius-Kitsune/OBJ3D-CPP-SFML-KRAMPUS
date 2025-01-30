#include "TriangleActor.h"

TriangleActor::TriangleActor(Level* _level, const float _radius, const string& _path, const IntRect& _rect)
						   : MeshActor(_level, _radius, 3, _path, _rect)
{

}