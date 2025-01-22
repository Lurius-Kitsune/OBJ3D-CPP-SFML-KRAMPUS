#pragma once
#include "Singleton.h"
#include "SoundSample.h"
#include "MusicSample.h"
#include "Sample.h"

enum AudioExtensionType
{
	MP3,
	WAV
};

class AudioManager : public Singleton<AudioManager>
{
	bool isMuted;
	float volume;
	string prefixPath;
	multimap<string, Sample*> allSamples;

public: 
	FORCEINLINE void RegisterSample(Sample* _sample)
	{
		allSamples.insert(make_pair(_sample->GetPath(), _sample));
	}
	FORCEINLINE string GetExtension(const AudioExtensionType& _type)
	{
		return vector<string>({ ".mp3", ".wav" })[_type];
	}

public:
	AudioManager();
	~AudioManager();

	template<typename SampleType, typename = enable_if<is_base_of_v<Sample, SampleType>>::type>
	SampleType* PlaySample(const string& _path, const AudioExtensionType& _type = MP3)
	{
		//static_assert(is_base_of_v<Sample, SampleType>, "ERREUR CUSTOM");
		const string& _finalPath = prefixPath + _path + GetExtension(_type);

		using Iterator = multimap<string, Sample*>::iterator;
		const pair<Iterator, Iterator>& _activeSamples = allSamples.equal_range(_finalPath);
		Sample* _sample;

		for (Iterator _iterator = _activeSamples.first; _iterator != _activeSamples.second; ++_iterator)
		{
			_sample = _iterator->second;
			if (_sample->IsAvailable())
			{
				_sample->Play();
				return Cast<Sample, SampleType>(_sample);
			}
		}

		_sample = new SampleType(_finalPath);
		_sample->Play();

		return Cast<Sample, SampleType>(_sample);
	}
	void ToggleMute();
};