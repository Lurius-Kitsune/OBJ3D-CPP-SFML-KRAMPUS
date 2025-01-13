#include "ShapeObject.h"
#include "TextureManager.h"

ShapeObject::ShapeObject(const float _radius, const string& _path, const size_t& _pointCount, const IntRect& _rect)
{
	shape = new CircleShape(_radius, _pointCount);
	TextureManager::GetInstance().Load(this, _path, _rect);
}

ShapeObject::ShapeObject(const Vector2f& _size)
{
	shape = new RectangleShape(_size);
}

ShapeObject::~ShapeObject()
{
	delete shape;
}

