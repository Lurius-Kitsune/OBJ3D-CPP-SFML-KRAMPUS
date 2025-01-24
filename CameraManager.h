#pragma once
#include "Singleton.h"
#include "CameraActor.h"
#include "Level.h"
class CameraManager : public Singleton<CameraManager>
{
	map<string, CameraActor*> allCameras;
	CameraActor* current;

	using OnRenderWindow = function<void(RenderWindow&)>;
	map<u_int, OnRenderWindow> onRenderWindow;

public:
	FORCEINLINE u_int BindOnRenderWindow(OnRenderWindow _callback)
	{
		u_int _id = GetUniqueID();
		onRenderWindow.insert({ _id, _callback });
		return _id;
	}
	FORCEINLINE void UnbindOnRenderWindow(const u_int& _uniqueId)
	{
		onRenderWindow.erase(_uniqueId);
	}
	FORCEINLINE map<string, CameraActor*> GetAllCameras() const
	{
		return allCameras;
	}

	FORCEINLINE CameraActor* GetCurrent() const
	{
		return current;
	}
	FORCEINLINE CameraActor* GetCameraByName(const string& _name, const bool _createIfNotExist = false)
	{
		if (!allCameras.contains(_name)) return nullptr;
		return allCameras.at(_name);
	}

	FORCEINLINE void SetCurrent(CameraActor* _camera)
	{
		if (!_camera) return;
		current = _camera;
	}

private:
	FORCEINLINE void Register(CameraActor* _camera)
	{
		if (!_camera) return;
		allCameras.insert({ _camera->GetDisplayName(), _camera });
	}

public:
	CameraManager();
	~CameraManager();

public:

	void RenderAllCameras(RenderWindow& _window);

	template<typename Type = CameraActor, IS_BASE_OF(CameraActor, Type)>
	Type* CreateCamera(const string& _name = "Camera")
	{
		Type* _camera = Level::SpawnActor(Type(_name));

		if (!current)
		{
			SetCurrent(_camera);
		}
	}

	void BeginPlay();
	void Tick(const float _deltaTime);
	void BeginDestroy();
};

