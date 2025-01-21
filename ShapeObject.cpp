#include "ShapeObject.h"
#include "TextureManager.h"

ShapeObject::ShapeObject(const float _radius, const string& _path, const IntRect& _rect,
	const size_t& _pointCount)
{
	objectData = new ShapeObjectData(SOT_CIRCLE, CircleShapeData(_radius, _path, _rect, _pointCount));
	InitCircle(objectData->data->circleData);
}

ShapeObject::ShapeObject(const Vector2f& _size, const string& _path, const IntRect& _rect)
{
	objectData = new ShapeObjectData(SOT_RECTANGLE, RectangleShapeData(_size, _path, _rect));
	InitRectangle(objectData->data->rectangleData);
}

ShapeObject::ShapeObject(const ShapeObject& _other)
{
	objectData = new ShapeObjectData(*_other.objectData);

	if (objectData->type == SOT_CIRCLE)
	{
		InitCircle(objectData->data->circleData);
	}

	else if (objectData->type == SOT_RECTANGLE)
	{
		InitRectangle(objectData->data->rectangleData);
	}
}

ShapeObject::~ShapeObject()
{
	delete shape;
	delete objectData;
}


void ShapeObject::InitCircle(const CircleShapeData& _data)
{
	shape = new CircleShape(_data.radius, _data.pointCount);
	TextureManager::GetInstance().Load(this, _data.path, _data.rect);
}

void ShapeObject::InitRectangle(const RectangleShapeData& _data)
{
	shape = new RectangleShape(_data.size);
	TextureManager::GetInstance().Load(this, _data.path, _data.rect);
}