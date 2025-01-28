#pragma once
#include "CoreMinimal.h"

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


	class Widget
	{
		VisibilityType visibility;

	public:
		FORCEINLINE void SetVisibility(const VisibilityType& _visibility)
		{
			visibility = _visibility;
		}

	public:
		Widget();
		virtual ~Widget() = default;

	public:
		virtual void Render(RenderWindow& _window) = 0;
	};
}

