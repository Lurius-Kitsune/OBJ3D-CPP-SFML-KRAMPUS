#include "TextObject.h"
#include "FontManager.h"

TextObject::TextObject(const string& _text, const string& _fontPath, const FontExtensionType& _fontType)
{
	text = new Text(font, _text);
	M_FONT.Load(this, _fontPath, _fontType);
}

TextObject::~TextObject()
{
	delete text;
}
