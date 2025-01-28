#include "Label.h"
#include "CameraManager.h"

using namespace Camera;

UI::Label::Label(const string& _text, const RenderType& _type, const string& _path, const FontExtensionType& _fontType) 
	: Widget("Label", _type)
{
	text = new TextObject(_text, _path, _fontType);

	const RenderData& _renderData = RenderData(bind(&Label::Render, this, placeholders::_1), Screen);
	textMeshToken = M_CAMERA.BindOnRenderWindow(_renderData);
}

UI::Label::~Label()
{
	delete text;
}


void UI::Label::Render(RenderWindow& _window)
{
	_window.draw(*text->GetDrawable());
}