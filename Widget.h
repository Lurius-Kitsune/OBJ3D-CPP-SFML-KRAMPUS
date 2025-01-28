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
	};
}

