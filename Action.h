#pragma once
#include "CoreMinimal.h"
namespace Input
{

	typedef optional<Event> EventInfo;

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
		ValueType value;
		type_index trigger;
	};

	class Action
	{
		string name;
		ActionData data;
		vector<int> inputs;
		function<void()> callback;

	public:

		void TryToExecute(const EventInfo& _event)
		{
			type_index _type = typeid(_event.value());
			if (data.trigger == _type)
			{
				callback();
			}
		}
	};
}

