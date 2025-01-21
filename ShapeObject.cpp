#include "ShapeObject.h"
#include "TextureManager.h"

ShapeObject::ShapeObject(const float _radius, const string& _path, const size_t& _pointCount, const IntRect& _rect)
{
	objectData->type = SOT_CIRCLE;
	objectData->data.circleData = { _radius, _path, _rect , _pointCount };
	InitCircle(objectData->data.circleData);
}

ShapeObject::ShapeObject(const Vector2f& _size, const string& _path, const IntRect& _rect)
{
	objectData->type = SOT_RECTANGLE;
	objectData->data.rectangleData = { _size, _path,_rect };
	InitRectangle(objectData->data.rectangleData);
}

ShapeObject::ShapeObject(const ShapeObject& _other)
{
	const ShapeObjectData* _data = _other.objectData;
	if (_data->type == SOT_CIRCLE)
	{
		InitCircle(_data->data.circleData);
	}
	else if (_data->type == SOT_RECTANGLE)
	{
		InitRectangle(_data->data.rectangleData);
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
	shape = new RectangleShape();
	TextureManager::GetInstance().Load(this, _data.path, _data.rect);

}

