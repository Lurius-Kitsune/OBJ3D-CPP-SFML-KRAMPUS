#include "RectangleActor.h"

RectangleActor::RectangleActor(const Vector2f& _size, const string& _path, const float _lifespan, const TextureExtensionType& _textureType, const IntRect& _rect)
							 : MeshActor(_size, _path, _lifespan, _textureType, _rect)
{

}