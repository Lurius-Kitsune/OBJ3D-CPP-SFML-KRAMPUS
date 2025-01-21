#pragma once
#include "Singleton.h"
#include "SoundSample.h"

enum SoundExtensionType
{
	MP3,
	WAV
};

class SoundManager : public Singleton<SoundManager>
{
	bool isMuted;
	float volume;
	string prefixPath;
	multimap<string, SoundSample*> allSamples;

public: 
	FORCEINLINE void RegisterSample(SoundSample* _sample)
	{
		allSamples.insert(make_pair(_sample->GetPath(), _sample));
	}
	FORCEINLINE string GetExtension(const SoundExtensionType& _type)
	{
		return vector<string>({ ".mp3", ".wav" })[_type];
	}

public:
	SoundManager();
	~SoundManager();

	SoundSample* PlaySound(const string& _path, const SoundExtensionType& _type = MP3);
	void ToggleMute();
};