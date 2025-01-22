#pragma once
#include "CoreMinimal.h"

class Sample
{
protected:
	float volume;
	string path;

	FORCEINLINE virtual void UpdateVolume(const float _volume) = 0;
	FORCEINLINE virtual int GetStatus() const = 0;
	FORCEINLINE virtual bool IsStatusByIndex(const u_int& _statusIndex)
	{
		return GetStatus() == _statusIndex;
	}
public:
	FORCEINLINE virtual void SetLoop(const bool _isLoop) = 0;
	FORCEINLINE virtual bool SetPitch(const float _pitch) = 0;
	FORCEINLINE virtual bool IsAvailable() const = 0;

	FORCEINLINE string GetPath() const
	{
		return path;
	}

	FORCEINLINE float GetVolume() const
	{
		return volume;
	}

	FORCEINLINE void SetMuteStatus(const bool _status)
	{
		UpdateVolume(_status ? 0.0f : volume);
	}
	FORCEINLINE void SetVolume(const float _volume)
	{
		UpdateVolume(volume = _volume);
	}


public:
	Sample(const string& _path);
	virtual ~Sample() = default;
public:
	virtual void Play(const Time& _time = Time());
	virtual void Pause() = 0;
	virtual void Stop() = 0;
};