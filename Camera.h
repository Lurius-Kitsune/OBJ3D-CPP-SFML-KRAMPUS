#pragma once
#include "Actor.h"
class Camera : public Actor
{
	string name;
	Window* window;
	View view;

public:

	FORCEINLINE string GetName() const
	{
		return name;
	}

	FORCEINLINE View GetView() const
	{
		return view;
	}

	Camera(Window* _window, const string& _name, const FloatRect& _viewRect);
	virtual ~Camera();

public:

	void SetViewRect(const FloatRect& _viewRect);

	virtual void SetPosition(const Vector2f& _position) override;
	virtual void SetRotation(const Angle& _rotation) override;
	virtual void SetScale(const Vector2f& _scale) override;
	virtual void SetToDelete() override;
	virtual void Move(const Vector2f& _offset) override;

private:
	virtual void SetOrigin(const Vector2f& _origin) override;
	virtual void Construct() override;
	virtual void Deconstruct() override;
};

