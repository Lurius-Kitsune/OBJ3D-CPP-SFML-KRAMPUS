#include "SquareActor.h"

SquareActor::SquareActor(const string& _name, const float _size, const string& _path, const TextureExtensionType& _textureType, const IntRect& _rect)
					   : RectangleActor(_name, Vector2f(_size, _size), _path, _textureType, _rect)
{

}