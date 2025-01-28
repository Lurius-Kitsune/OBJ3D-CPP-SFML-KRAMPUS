#include "Widget.h"
#include "CameraManager.h"

using namespace Camera;

UI::Widget::Widget(const string& _name, const RenderType& _type)
	: Actor(_name)
{
	visibility = Visible;
	renderToken = 0;
	type = _type;
}

UI::Widget::Widget(const Widget& _other)
	: Actor(_other)
{
	visibility = _other.visibility;
	type = _other.type;
	Construct();
}

void UI::Widget::Construct()
{
	const RenderData& _renderData = RenderData(bind(&Widget::Render, this, _1), type);
	renderToken = M_CAMERA.BindOnRenderWindow(_renderData);
}

void UI::Widget::Deconstruct()
{
	M_CAMERA.UnbindOnRenderWindow(renderToken);
}
