#pragma once
#include "CoreMinimal.h"

class SoundSample
{
	Sound* sound;
	SoundBuffer buffer;

public:
	FORCEINLINE void SetVolume(const float _volume)
	{
		sound->setVolume(_volume);
	}
	FORCEINLINE void SetLoop(const bool _isLoop)
	{
		sound->setLooping(_isLoop);
	}
	FORCEINLINE void SetPitch(const float _pitch)
	{
		sound->setPitch(_pitch);
	}
	FORCEINLINE float GetVolume()
	{
		sound->getVolume();
	}

public:
	SoundSample(const string& _path);
	~SoundSample();

public:
	void Play(const Time& _time = Time());
	void Pause();
	void Stop();
};

