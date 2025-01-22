#pragma once

#include "Singleton.h"
#include "Camera.h"
#include "ActorManager.h"

class CameraManager : public Singleton<CameraManager>
{
	map<string, Camera*> allCameras;
	Camera* currentCamera;

public:

	FORCEINLINE Camera* GetCamera(const string& _name) const
	{
		return allCameras.at(_name);
	}

	FORCEINLINE void AddCamera(Camera* _camera)
	{
		allCameras.emplace(_camera->GetName(), _camera);
	}

	FORCEINLINE void RemoveCamera(const string& _cameraName)
	{
		if (Camera* _camera = GetCamera(_cameraName))
		{
			if (currentCamera == _camera) currentCamera = nullptr;
			allCameras.erase(_cameraName);
		}

	}

	FORCEINLINE Camera* GetCurrentCamera()
	{
		return currentCamera;
	}

	FORCEINLINE void SetCurrentCamera(Camera* _camera)
	{
		currentCamera = _camera;
	}


public:
	void Destroy();
};

