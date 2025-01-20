#pragma once
#include "Actor.h"
#include "TextObject.h"

class Label : public Actor
{
	TextObject* text;
	u_int renderMeshToken;
public :
	Label(const string& _text, const string& _fontPath = "", const FontExtensionType& _fontType = TTF);
	~Label();

public:
	void RenderMesh(RenderWindow& _window);
};

