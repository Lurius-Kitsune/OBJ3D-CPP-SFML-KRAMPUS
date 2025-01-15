#include "SoundManager.h"

SoundManager::SoundManager()
{
	allSamples = multimap<string, SoundSample*>();
	isMuted = false;
	Volume = 1.0f;
}

SoundManager::~SoundManager()
{
	for (pair<string, SoundSample*> _samplePair : allSamples)
	{
		delete _samplePair.second;
	}
}

void SoundManager::PlaySound(const string& _path)
{
	if (allSamples.find(_path) == allSamples.end())
	{
		LOG(Warning, "No sound named '" + _path + "' exist.");
		return;
	}
	for (pair<string, SoundSample*> _samplePair : allSamples)
	{
		if (_samplePair.first == _path)
		{
			SoundSample* _sample = _samplePair.second;
			if (_sample->GetStatus())
			{
				_sample->SetMuteStatus(isMuted);
				_sample->Play();
				break;
			}
		}
	}
}

void SoundManager::ToogleMute()
{
	isMuted = !isMuted;
	for (pair<string, SoundSample*> _samplePair : allSamples)
	{
		_samplePair.second->SetMuteStatus(isMuted);
	}
}
