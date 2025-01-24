#include "SquareActor.h"

SquareActor::SquareActor(const float _size, const string& _path, const float _lifespan, const TextureExtensionType& _textureType, const IntRect& _rect)
					   : RectangleActor(Vector2f(_size, _size), _path,_lifespan, _textureType, _rect)
{

}