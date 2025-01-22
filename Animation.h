#pragma once
#include "CoreMinimal.h"
#include "ShapeObject.h"
#include "TimerManager.h"

enum ReadDirection
{
	RD_ROW = 1,
	RD_ROW_REVERSE = -1,
	RD_COLUMN = 1,
	RD_COLUMN_REVERSE = -1,
};

struct SpriteData
{
	Vector2f start;
	Vector2f sizes;
};

struct LinkedAnimation
{
	function<bool()> transition;
	class Animation* animation;

	FORCEINLINE bool IsValid()const
	{
		return !transition || transition();
	}

	bool TryToChange()
	{
		if (!IsValid()) return false;
		//animation->Start(); // TODO
		return true;
	}
};

struct AnimationData
{
	bool canLoop;
	bool hasExitTime;
	int count;
	float duration;
	vector<float> timesBetween;
	vector<SpriteData> sprite;
	ReadDirection direction;
	vector<LinkedAnimation> linkedAnimations;

	AnimationData() = default;

	AnimationData(const int _count, const float _duration, const SpriteData& _spriteData,
		const ReadDirection& _direction = RD_ROW,const bool _canLoop = true, const bool _hasExitTime = true,
		const vector<LinkedAnimation>& _linkedAnimations = {})
	{
		canLoop = _canLoop;
		hasExitTime = _hasExitTime;
		count = _count;
		duration = _duration;
		for (u_int _i = 0; _i < _count; _i++)
		{
			sprite.push_back(_spriteData);
		}
		direction = _direction;
		linkedAnimations = _linkedAnimations;
	}

	AnimationData(const int _count, const float _duration, const vector<SpriteData>& _spriteDatas,
		const ReadDirection& _direction = RD_ROW, const bool _canLoop = true, const bool _hasExitTime = true,
		const vector<LinkedAnimation>& _linkedAnimations = {})
	{
		canLoop = _canLoop;
		hasExitTime = _hasExitTime;
		count = _count;
		duration = _duration;
		sprite = _spriteDatas;
		direction = _direction;
		linkedAnimations = _linkedAnimations;
	}
};

class Animation
{
	int currentIndex;
	AnimationData data;
	string name;
	ShapeObject* shape;
	Timer<Seconds>* timer;

public:
	Animation(const string& _name, ShapeObject* _object, const AnimationData& _data);
};

