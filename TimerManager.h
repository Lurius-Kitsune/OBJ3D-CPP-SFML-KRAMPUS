#pragma once
#include "Singleton.h"
#include "Game.h"

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

template <typename DurationType = int32_t>
class TimerManager : public Singleton<TimerManager<DurationType>>
{
	// Objet qui contient toutes les données de temps
	Clock clock;
	// Temps en miliseconde depuis le début du prog
	DurationType time;
	// Stocke temporairement la précédente durée de la frame
	DurationType lastTime;
	// Mettre à jours le content de FPS
	DurationType lastFrameTime;
	// Temps depuis la dernière image rendu 
	DurationType elapsedTime;
	// Temps depuis la dernière image rendu avec le timeScale
	DurationType deltaTime;
	// Vitesse à laquelle le temps s'écoule
	DurationType timeScale;
	// NB image rendu depuis le début
	l_long framesCount;
	// MAximum d'image rendu par seconde
	u_short maxFrameRate;
	// Nombre d'image rendu par seconde
	DurationType fps;
	// Collection de tous les time existant
	set<Timer*> allTimers;

public:
	FORCEINLINE set<Timer*> GetAllTimers() const
	{
		return allTimers;
	}

	FORCEINLINE void AddTimer(Timer* _timer)
	{
		allTimers.insert(_timer);
	}

	FORCEINLINE void SetTimerScale(const DurationType& _timeScale)
	{
		timeScale = _timeScale;
	}
	FORCEINLINE void ComputeFPS() const
	{
		return 1000.0f / (time - lastFrameTime);
	}

public:
	TimerManager()
	{
		clock = Clock();
		time = DurationType();
		lastTime = DurationType();
		elapsedTime = DurationType();
		deltaTime = DurationType();
		timeScale = DurationType();
		framesCount = 0;
		maxFrameRate = 50;
		fps = DurationType();
		allTimers = set<Timer*>();
	}
	~TimerManager()
	{
		for (Timer* _timer : allTimers)
		{
			delete _timer;
		}
	}

public:
	void Update()
	{
		lastTime = time;
		time = clock.getElapsedTime().asMilliseconds();
		elapsedTime = time - lastTime;
		framesCount++;

		if (lastFrameTime == 0 || time - lastFrameTime >= 1000.f / maxFrameRate)
		{
			lastFrameTime = time;
			Game::GetInstance().UpdateWindow();
		}

		for (Timer* _timer : allTimers)
		{
			_timer->Update(1.0f);
		}
	}
	void Pause()
	{
		for (Timer* _timer : allTimers)
		{
			_timer->Pause();
		}
	}

private:

};
using TM_Seconds = TimerManager<int32_t>;

