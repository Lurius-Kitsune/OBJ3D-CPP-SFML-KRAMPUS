#include "CameraManager.h"

CameraManager::CameraManager()
{

}

CameraManager::~CameraManager()
{
}

void CameraManager::RenderAllCameras(RenderWindow& _window)
{
	for (const pair<string, CameraActor*>& _cameraPair : allCameras)
	{
		_window.setView(*_cameraPair.second->GetView());
		
		for (const pair<u_int, OnRenderWindow>& _renderPair : onRenderWindow)
		{
			_renderPair.second(_window);
		}
	}

	_window.setView(_window.getDefaultView());
}

void CameraManager::BeginPlay()
{
}

void CameraManager::Tick(const float _deltaTime)
{
}

void CameraManager::BeginDestroy()
{
}
