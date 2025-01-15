#pragma once
#include "Singleton.h"
class SoundManager : public Singleton<SoundManager>
{
	bool isMuted;
	float Volume;
};

