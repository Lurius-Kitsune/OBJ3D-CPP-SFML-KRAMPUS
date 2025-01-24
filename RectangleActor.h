#pragma once
#include "MeshActor.h"

class RectangleActor : public MeshActor
{
public:
	RectangleActor(const Vector2f& _size, const string& _path = "", const float _lifespan = 0.0f, const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
};