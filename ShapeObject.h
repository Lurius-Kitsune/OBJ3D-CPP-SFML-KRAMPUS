#pragma once
#include "Object.h"
class ShapeObject : public Object
{
	Shape* shape;

public:
	virtual Drawable* GetDrawable() const override
	{
		return shape;
	}

public:
};

