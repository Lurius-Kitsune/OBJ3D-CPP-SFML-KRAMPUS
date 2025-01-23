#pragma once
#include "MeshActor.h"

class RectangleActor : public MeshActor
{
public:
	RectangleActor(const string& _name, const Vector2f& _size, const string& _path = "", const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
};