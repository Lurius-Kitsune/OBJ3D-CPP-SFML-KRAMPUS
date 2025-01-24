#include "Label.h"
#include "GameManager.h"

Label::Label(const string& _text, const string& _path, const FontExtensionType& _fontType) : Actor("Label")
{
	text = new TextObject(_text, _path, _fontType);

	textMeshToken = M_GAME.GetCurrent()->BindOnRenderWindow(bind(&Label::RenderText, this, placeholders::_1));
}

Label::~Label()
{
	delete text;
}


void Label::Deconstruct()
{
	Super::Deconstruct();
	M_GAME.GetCurrent()->UnbindOnRenderWindow(textMeshToken);
}


void Label::RenderText(RenderWindow& _window)
{
	_window.draw(*text->GetDrawable());
}