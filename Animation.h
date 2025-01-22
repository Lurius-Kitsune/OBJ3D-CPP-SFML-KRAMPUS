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

struct AnimationData
{
	bool canLoop;
	int count;
	vector<float> timesBetween;
	float duration;
	vector<SpriteData> sprite;
	ReadDirection direction;

	AnimationData(const int _count, const float _duration, const SpriteData& _spriteData, const ReadDirection& _direction = RD_ROW,
		const bool _canLoop = false)
	{
		canLoop = _canLoop;
		count = _count;
		duration = _duration;
		for (u_int _i = 0; _i < _count; _i++)
		{
			sprite.push_back(_spriteData);
		}
		direction = _direction;
	}

	AnimationData(const int _count, const float _duration, const vector<SpriteData>& _spriteDatas, const ReadDirection& _direction = RD_ROW,
		const bool _canLoop = false)
	{
		canLoop = _canLoop;
		count = _count;
		duration = _duration;
		sprite = _spriteDatas;
		direction = _direction;
	}
};

class Animation
{
	int currentIndex;
	string name;
	ShapeObject path;
	Timer<Seconds>* timer;

public:
	Animation(const string& _path);
};

