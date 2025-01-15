#pragma once
#include "Singleton.h"
#include "SoundSample.h"
class SoundManager : public Singleton<SoundManager>
{
	multimap<string, SoundSample*> allSamples;
	bool isMuted;
	float Volume;

public:
	FORCEINLINE void ResgisterSample(SoundSample* _sample)
	{
		allSamples[_sample->GetPath()] = _sample;
	}

public:
	SoundManager();
	~SoundManager();

public:
	void PlaySound(const string& _path);
	void ToogleMute();
};

