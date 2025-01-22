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
	float timesBetween;
	Vector2i start;
	Vector2i size;
};

struct LinkedAnimation
{
	function<bool()> transition;
	class Animation* animation;

	FORCEINLINE bool IsValid()const
	{
		return !transition || transition();
	}

	bool TryToChange();
};

struct AnimationData
{
	bool canLoop;
	bool hasExitTime;
	bool isReversed;
	int count;
	float duration;
	vector<float> timesBetween;
	vector<SpriteData> sprite;
	ReadDirection direction;
	vector<LinkedAnimation> linkedAnimations;

	AnimationData() = default;

	AnimationData(const int _count, const float _duration, const SpriteData& _spriteData,
		const ReadDirection& _direction = RD_ROW, const bool _isReversed = false,
		const bool _canLoop = true, const bool _hasExitTime = true,
		const vector<LinkedAnimation>& _linkedAnimations = {})
	{
		canLoop = _canLoop;
		hasExitTime = _hasExitTime;
		isReversed = _isReversed;
		count = _count;
		duration = _duration;

		const function<Vector2i(const int _i)> _computeStart[] =
		{
			[&](const int _i)
			{
				return Vector2i
				{
					_spriteData.start.x + _i * _spriteData.size.x,
					 _spriteData.start.y
				};

			},

			[&](const int _i)
			{
			return Vector2i
				{
					_spriteData.start.x - _i * _spriteData.size.x,
					 _spriteData.start.y
				};
			},

			[&](const int _i)
			{
				return Vector2i
					{
						_spriteData.start.x,
						 _spriteData.start.y + _i * _spriteData.size.y
					};
			},
			[&](const int _i)
			{
				return Vector2i
					{
						_spriteData.start.x,
						 _spriteData.start.y - _i * _spriteData.size.y
					};
			},
		};

		for (int _i = 0; _i < _count; _i++)
		{
			const SpriteData& _data = { _spriteData.timesBetween, _computeStart[direction](_i), _spriteData.size};
			sprite.push_back(_spriteData);
		}
		direction = _direction;
		linkedAnimations = _linkedAnimations;
	}

	AnimationData(const int _count, const float _duration, const vector<SpriteData>& _spriteDatas,
		const ReadDirection& _direction = RD_ROW, const bool _isReversed = false,
		const bool _canLoop = true, const bool _hasExitTime = true,
		const vector<LinkedAnimation>& _linkedAnimations = {})
	{
		canLoop = _canLoop;
		hasExitTime = _hasExitTime;
		isReversed = _isReversed;
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
	
private:
	FORCEINLINE bool IsValidIndex() const
	{
		return currentIndex < data.count ;
	}

public:
	FORCEINLINE string GetName() const
	{
		return name;
	}

public:
	Animation(const string& _name, ShapeObject* _object, const AnimationData& _data);
	Animation(const Animation& _other);
	~Animation();

public:
	void Start();
	void Resume();
	void Pause();
	void Stop();
private:
	void Update();
	void Reset();
};

