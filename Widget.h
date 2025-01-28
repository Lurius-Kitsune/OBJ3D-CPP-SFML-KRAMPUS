#pragma once
#include "Actor.h"
#include "CoreMinimal.h"
#include "RenderType.h"

namespace UI
{
	enum VisibilityType
	{
		Hidden,
		Collapsed,
		Disabled,
		UninteractibleSelf,
		UninteractibleSelfAndChildren,
		Visible,
	};


	class Widget : public Actor
	{
		VisibilityType visibility;
		u_int renderToken;
		RenderType type;

	public:
		FORCEINLINE void SetVisibility(const VisibilityType& _visibility)
		{
			visibility = _visibility;
		}

	public:
		Widget(const string& _name = "Widget", const RenderType& _type = Screen);
		Widget(const Widget& _other);
		virtual ~Widget() = default;

	public:
		virtual void Construct() override;
		virtual void Deconstruct() override;
		virtual void Render(RenderWindow& _window) = 0;
	};
}

