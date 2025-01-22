#pragma once
#include "Actor.h"

class Camera : public Actor
{
	View* camera;
	Vector2f size;
	Actor* parent;


public:
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		camera->setCenter(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		camera->setRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		camera->setSize(_scale);
	}

public:
	Camera( Actor* _parent, const Vector2f& _size, const Vector2f& _posCenter, const Actor& _owner);

public:
	void Update();
	virtual void Tick(const float _deltaTime) override;


};

