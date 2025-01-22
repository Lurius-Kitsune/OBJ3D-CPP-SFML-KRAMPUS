#include "SoundSample.h"
#include "AudioManager.h"

SoundSample::SoundSample(const string& _path)
	: Sample(_path)
{

	if (!buffer.loadFromFile(_path))
	{
		LOG(Error, "Invalid path : " + _path);
		sound = nullptr;
		return;
	}

	sound = new Sound(buffer);
	M_AUDIO.RegisterSample(this);
}

SoundSample::~SoundSample()
{
	delete sound;
}


void SoundSample::Play(const Time& _time)
{
	Super::Play();
	sound->play();
	sound->setPlayingOffset(_time);
}

void SoundSample::Pause()
{
	sound->pause();
}

void SoundSample::Stop()
{
	sound->stop();
}
