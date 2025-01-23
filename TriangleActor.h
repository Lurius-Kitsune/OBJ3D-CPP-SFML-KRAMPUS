#pragma once
#include "MeshActor.h"

class TriangleActor : public MeshActor
{
public:
	TriangleActor(const string& _name, const float _radius, const string& _path = "", const IntRect& _rect = {});
};