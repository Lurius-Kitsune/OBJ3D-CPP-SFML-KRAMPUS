#include "Camera.h"

Camera::Camera(const Vector2f& _centerPosition, const Vector2f& _size)
{
	view = new View(_centerPosition, _size);
}

Camera::Camera(const FloatRect& _viewRect)
{
	view = new View(_viewRect);
}

Camera::~Camera()
{
	delete view;
}
