#pragma once
#include "CoreMinimal.h"
#include "ActorManager.h"
#include "CameraManager.h"

using namespace Camera;

class Level
{
	ActorManager actors;
	CameraManager cameras;

public:

#pragma region Actors

	template <typename T = Actor>
	FORCEINLINE T* SpawnActor()
	{
		const SubclassOf<T>& _ref = SubclassOf(T());
		return SpawnActor(_ref);
	}

	template <typename T = Actor>
	FORCEINLINE T* SpawnActor(const SubclassOf<T>& _ref)
	{
		T* _actor = new T(_ref.GetObject());
		_actor->Construct();
		return _actor;
	}

	template <typename T = Actor>
	FORCEINLINE T* SpawnActor(const T& _ref)
	{
		T* _actor = new T(_ref);
		_actor->Construct();
		return _actor;
	}

	FORCEINLINE set<Actor*> GetAllActors() const
	{
		return actors.GetAllActors();
	}

#pragma endregion

#pragma region Cameras

	FORCEINLINE CameraManager* GetCameraManager() const
	{
	}

#pragma endregion


	Level();

	// TODO move to PlayerController
	//static void SetViewTarget()

	virtual void OnLoad();
	virtual void OnExit();
	virtual void OnDestroy();

};