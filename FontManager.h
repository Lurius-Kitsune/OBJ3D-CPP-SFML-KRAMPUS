#pragma once
#include "Singleton.h"
#include "TextObject.h"

class FontManager : public Singleton<FontManager>
{
	string defaultFontPath;
	string defaultFontExtension;
	Font* defaultFont;

private:
	// Lazy pointeur
	FORCEINLINE Font GetDefaultFont()
	{
		if (!defaultFont)
		{
			LoadDefaultFont();
		}

		return *defaultFont;
	}

public:
	FontManager();
	~FontManager();
public:
	void Load(TextObject* _shape, const string& _path, const FontExtensionType& _fontType);

private:
	void LoadFont(Font& _texture, const string& _path, const IntRect& _rect = IntRect());
	void LoadDefaultFont();
	void SetFont(Text* _text, const Font* _font);
	string GetExtensionNameByType(const FontExtensionType& _fontType) const;
};

