#pragma once
#include "Object.h"
class TextObject : public Object
{
	Text* text;

public:
	virtual Drawable* GetDrawable() const override
	{
		return text;
	}

public:
};

