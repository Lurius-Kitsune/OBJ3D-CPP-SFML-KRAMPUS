#include "Label.h"
#include "Game.h"

Label::Label(const string& _text, const string& _fontPath, const FontExtensionType& _fontType)
{
	text = new TextObject(_text, _fontPath, _fontType);
	renderMeshToken = M_GAME.BindOnRenderWindow(bind(&Label::RenderMesh, this, placeholders::_1));
}

Label::~Label()
{
	delete text;
}

void Label::RenderMesh(RenderWindow& _window)
{
	_window.draw(*text->GetDrawable());
}
