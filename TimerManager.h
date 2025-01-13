#pragma once
#include "Singleton.h"

class Timer
{
	float currentTime;
	double duration;
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

	FORCEINLINE double GetCurrentTime() const
	{
		return currentTime;
	}

public:
	Timer(const function<void()>& _callback, const Time& _time, const bool _startRunning = false,
		const bool _isLoop = false);

public:
	void Start();
	void Update(const float _deltaTime);
	void Stop();
	void Resume();
	void Reset();
	void Pause();
};

class TimerManager : public Singleton<TimerManager>
{
	set<Timer*> allTimers;

public:
	FORCEINLINE set<Timer*> GetAllTimers() const
	{
		return allTimers;
	}

	FORCEINLINE void AddActor(Timer* _timer)
	{
		allTimers.insert(_timer);
	}

public:
	TimerManager();
	~TimerManager();

public:
	void Update();
	void Pause();

private:

};

