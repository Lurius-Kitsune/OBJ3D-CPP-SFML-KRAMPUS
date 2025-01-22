#pragma once
#include "CoreMinimal.h"
#include "Sample.h"

class SoundSample : public Sample
{
	using SoundStatus = SoundSource::Status;

	float volume;
	string path;
	Sound* sound;
	SoundBuffer buffer;
#pragma region Sample
	FORCEINLINE virtual void UpdateVolume(const float _volume) override
	{
		sound->setVolume(_volume);
	}
	FORCEINLINE virtual int GetStatus() const override
	{
		return CAST(int,sound->getStatus());
	}
public:
	FORCEINLINE virtual void SetLoop(const bool _isLoop) override
	{
		sound->setLooping(_isLoop);
	}
	FORCEINLINE virtual bool SetPitch(const float _pitch) override
	{
		float _newPitch = sound->getPitch() + _pitch;
		if (_newPitch > 100.0f || _newPitch < 0.0f) return false;
		sound->setPitch(_newPitch);
		return true;
	}
	FORCEINLINE virtual bool IsAvailable() const override
	{
		return CAST(SoundStatus, GetStatus()) != SoundStatus::Playing;
	}
	
	#pragma endregion

public:
	SoundSample(const string& _path);
	~SoundSample();

	virtual void Play(const Time& _time = Time()) override;
	virtual void Pause() override;
	virtual void Stop() override;
};