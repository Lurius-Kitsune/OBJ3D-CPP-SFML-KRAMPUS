#pragma once
#include "Component.h"
class CameraComponent : public Component
{
	View* view;

public:
	CameraComponent(Actor* _owner);
	CameraComponent(Actor* _owner, const Vector2f& _start, const Vector2f& _size);
	CameraComponent(Actor* _owner, const FloatRect& _rect);
	CameraComponent(Actor* _owner, const CameraComponent* _other);
	~CameraComponent();
};

