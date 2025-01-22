#include "Sample.h"

Sample::Sample(const string& _path)
{
	volume = 100.0f;
	path = _path;
}

void Sample::Play(const Time& _time)
{
	if (IsStatusByIndex(0))
	{
		//sound->stop();
	}

	SetVolume(volume);
}
