#include "SoundSample.h"
#include "SoundManager.h"

SoundSample::SoundSample(const string& _path)
{
	volume = 100.0f;
	path = _path;

	if (!buffer.loadFromFile(_path))
	{
		LOG(Error, "Invalid path : " + _path);
		sound = nullptr;
		return;
	}

	sound = new Sound(buffer);
	M_SOUND.RegisterSample(this);
}

SoundSample::~SoundSample()
{
	delete sound;
}


void SoundSample::Play(const Time& _time)
{
	if (GetStatus() == SoundStatus::Paused)
	{
		sound->stop();
	}

	SetVolume(volume);
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
