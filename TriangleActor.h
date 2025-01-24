#pragma once
#include "MeshActor.h"

class TriangleActor : public MeshActor
{
public:
	TriangleActor(const float _radius, const string& _path = "", const float _lifespan = 0.0f, const IntRect& _rect = {});
};