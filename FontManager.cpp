#include "FontManager.h"

FontManager::FontManager()
{
	defaultFontExtension = ".ttf";
	defaultFontPath = "Teacher";
	defaultFont = nullptr;
}

FontManager::~FontManager()
{
	delete defaultFont;
}

void FontManager::Load(TextObject* _shape, const string& _path, const FontExtensionType& _fontType)
{
	Font& _font = _shape->GetFont();
	if (_path.empty())
	{
		LOG(Error, "Cannot open file with empty path");
		_font = GetDefaultFont();
	}
	const string _fontPath = _path + GetExtensionNameByType(_fontType);
	LoadFont(_font, _path);
	SetFont(_shape->GetDrawable(), &_font);
}


void FontManager::LoadFont(Font& _font, const string& _path, const IntRect& _rect)
{
	const string& _finalPath = "Assets/Fonts/" + _path + defaultFontExtension;
	if (!_font.openFromFile(_finalPath))
	{
		LOG(Error, "Cannot open file with path : \'" + _finalPath + "\'");
		_font = GetDefaultFont();
	}
}

void FontManager::LoadDefaultFont()
{
	defaultFont = new Font();
	LoadFont(*defaultFont, defaultFontPath);
}

void FontManager::SetFont(Text* _text, const Font* _font)
{
	_text->setFont(*_font);
}

string FontManager::GetExtensionNameByType(const FontExtensionType& _fontType) const
{
	const vector<string> _extensionNames =
	{
		".otf",
		".ttf"
	};

	return _extensionNames[_fontType];
}
