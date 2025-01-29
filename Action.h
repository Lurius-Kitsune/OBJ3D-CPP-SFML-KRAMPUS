#pragma once
#include "CoreMinimal.h"
namespace Input
{

	typedef optional<Event> Trigger;

	enum ControllerButtonsType
	{
		Start,
		Select,
		Cross,
		Cricle,
		Square,
		Triangle,
		L1,
		R1,
		L2,
		R2,
		LeftStick,
		RightStick,
	};

	enum ControllerAxisType
	{
		LeftStickX,
		LeftStickY,
		RightStickX,
		RightStickY,
	};


	enum ValueType
	{
		Digital, // bool
		Axis, // float
		Axis2, // Vector2f
	};

	struct ActionData
	{
		//ActionType type;
		function<void()> callback;

		int key;
		ControllerButtonsType buttonType;
		ControllerAxisType axisType;
	};

	class Action
	{
		string name;
		vector<int> inputs;
		function<void()> callback;
		ActionData data;
	};
}

