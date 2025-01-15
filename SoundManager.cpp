#include "SoundManager.h"

SoundManager::SoundManager()
{
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
		LOG(Warning, "No music named '" + _path + "' exist.");
		return;
	}

	allSamples[_path]->Play();
}

void SoundManager::ToogleMute()
{
	isMuted = !isMuted;
	for (SoundSample* _sample : activeSample)
	{
		_sample->SetMuteStatus(isMuted);
	}
}
