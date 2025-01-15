#include "SoundSample.h"

SoundSample::SoundSample(const string& _path)
{
	const string& _finalPath = "Assets/Sounds/" + _path;
	if (!buffer.loadFromFile(_finalPath))
	{
		LOG(Error, "Cannot open sound with path : \'" + _finalPath + "\'");
		return;
	}
	sound = new Sound(buffer);
}

SoundSample::~SoundSample()
{
	delete sound;
}

void SoundSample::Play(const Time& _time)
{
	sound->setPlayingOffset(_time);
	sound->play();
}

void SoundSample::Pause()
{
	sound->pause();
}

void SoundSample::Stop()
{
	sound->stop();
}
