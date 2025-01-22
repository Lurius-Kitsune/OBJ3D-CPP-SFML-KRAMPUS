#pragma once
#include "Sample.h"
#include "CoreMinimal.h"

class MusicSample : public Sample
{
	using MusicStatus = Music::Status;

	Music* music;

	#pragma region Sample
	FORCEINLINE virtual void UpdateVolume(const float _volume) override
	{
		music->setVolume(_volume);
	}
	FORCEINLINE virtual int GetStatus() const override
	{
		return CAST(int, music->getStatus());
	}
public:
	FORCEINLINE virtual void SetLoop(const bool _isLoop) override
	{
		music->setLooping(_isLoop);
	}
	FORCEINLINE virtual void SetPitch(const float _pitch) override
	{
		music->setPitch(_pitch);
	}
	FORCEINLINE virtual bool IsAvailable() const override
	{
		return CAST(MusicStatus, GetStatus()) != MusicStatus::Playing;
	}
	#pragma endregion
	FORCEINLINE float GetVolume() const
	{
		return music->getVolume();
	}
	

public:
	MusicSample(const string& _path);
	~MusicSample();

public:
	virtual void Play(const Time& _time = Time()) override;
	virtual void Pause() override;
	virtual void Stop() override;
};

