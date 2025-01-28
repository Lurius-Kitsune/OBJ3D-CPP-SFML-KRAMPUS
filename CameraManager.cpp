#include "CameraManager.h"

CameraManager::CameraManager()
{
	allRendersData = map<u_int, RenderData>();
	allCameras = map<string, CameraActor*>();
	current = nullptr;
}


void CameraManager::RenderAllCameras(RenderWindow& _window)
{
	// pour chaque caméra
	for (const pair<string, CameraActor*> _pair : allCameras)
	{
		// je draw tous les éléments que je veux
		for (const pair<u_int, RenderData>& _renderPair : allRendersData)
		{
			const bool _isWorld = _renderPair.second.type == World;
			const View& _view = _isWorld ? *_pair.second->GetView() : _window.getDefaultView();
			// je set sa view
			_window.setView(_view);
			_renderPair.second.callback(_window);
		}
	}
}