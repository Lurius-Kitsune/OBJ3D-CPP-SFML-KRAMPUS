#pragma once
#include "CoreMinimal.h"
#include "ActorManager.h"
#include "CameraManager.h"
using namespace Camera;

class Level
{
	string name;
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

	FORCEINLINE ActorManager& GetActorManager()
	{
		return actors;
	}

#pragma endregion

#pragma region Cameras

	FORCEINLINE CameraManager& GetCameraManager()
	{
		return cameras;
	}

	template <typename Type = CameraActor, typename ...Args, IS_BASE_OF(CameraActor, Type)>
	FORCEINLINE Type* CreateCamera(Args... _args)
	{
		Type* _camera = SpawnActor(Type(this, _args...));
		return cameras.AddCamera(_camera);
	}

#pragma endregion


	Level(const string& _name);

	// TODO move to PlayerController
	//static void SetViewTarget()

	virtual void Update(const float _deltaTime);
	virtual void OnLoad();
	virtual void OnExit();
	virtual void OnDestroy();

};