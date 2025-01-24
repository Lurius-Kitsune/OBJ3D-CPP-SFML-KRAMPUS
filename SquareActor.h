#pragma once
#include "RectangleActor.h"

class SquareActor : public RectangleActor
{
public:
	SquareActor(const float _size, const string& _path = "", const float _lifespan = 0.0f, const TextureExtensionType& _textureType = PNG, const IntRect& _rect = {});
};