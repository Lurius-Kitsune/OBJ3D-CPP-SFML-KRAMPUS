#include "Camera.h"
#include "CameraManager.h"

Camera::Camera(Window* _window, const string& _name, const FloatRect& _viewRect)
{
	name = _name;
	window = _window;
	view = View(_viewRect);
	Construct();
}

Camera::~Camera()
{
	LOG(Warning, "Destroyed camera " + name);
}

void Camera::SetViewRect(const FloatRect& _viewRect)
{
	view.setViewport(_viewRect);
}

void Camera::SetPosition(const Vector2f& _position)
{
	view.setCenter(_position);
	Super::SetPosition(_position);
}

void Camera::SetRotation(const Angle& _rotation)
{
	view.setRotation(_rotation);
	Super::SetRotation(_rotation);
}

void Camera::SetScale(const Vector2f& _scale)
{
	view.setSize(_scale);
	Super::SetScale(_scale);
}

void Camera::SetToDelete()
{
	Super::SetToDelete();
}

void Camera::Move(const Vector2f& _offset)
{
	view.move(_offset);
	Super::Move(_offset);
}

void Camera::SetOrigin(const Vector2f& _origin)
{
	SetPosition(_origin);
	Super::SetOrigin(_origin);
}

void Camera::Construct()
{
	M_CAMERA.AddCamera(this);
	Super::Construct();
	LOG(Display, "Registered camera " + name);
}

void Camera::Deconstruct()
{
	M_CAMERA.RemoveCamera(name);
	Super::Deconstruct();
}
