#pragma once
#include "TimerManager.h"

template <typename DurationType = MilliSec>
class Timer
{
	DurationType currentTime;
	DurationType duration;
	bool isRunning;
	bool isLoop;
	function<void()> callback;

public:
	FORCEINLINE bool IsRunning() const
	{
		return isRunning;
	}

	FORCEINLINE bool IsLoop() const
	{
		return isLoop;
	}

	FORCEINLINE DurationType GetCurrentTime() const
	{
		return currentTime;
	}

public:
	Timer(const function<void()>& _callback, const Time& _time, const bool _startRunning = false,
		const bool _isLoop = false)
	{
		isRunning = _startRunning;
		isLoop = _isLoop;
		currentTime = 0.0;
		duration = TimerManager<DurationType>::GetInstance().GetTime(_time);
		callback = _callback;
		TimerManager<DurationType>::GetInstance().AddTimer(this);
	}

public:
	void Start()
	{
		Reset();
		Resume();
	}
	void Update(const float _deltaTime)
	{
		if (!isRunning) return;

		currentTime += _deltaTime;
		if (currentTime >= duration)
		{
			if (callback)
			{
				callback();
			}

			if (!isLoop)
			{
				Stop();
			}

			Reset();
		}
	}
	void Stop()
	{
	}
	void Resume()
	{
		isRunning = true;
	}
	void Reset()
	{
		currentTime = 0.0;
	}
	void Pause()
	{
		isRunning = false;
	}

};