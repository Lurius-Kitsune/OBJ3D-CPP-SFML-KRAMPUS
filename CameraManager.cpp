#include "CameraManager.h"

Camera::CameraManager::CameraManager()
{
	allRendersData = map<u_int, RenderData>();
	allCameras = map<string, CameraActor*>();
	current = nullptr;
}


void Camera::CameraManager::RenderAllCameras(RenderWindow& _window)
{
	vector<RenderData> _renderWidgets;
	bool _isFirst = true;
	// pour chaque caméra
	for (const pair<string, CameraActor*> _pair : allCameras)
	{
		_window.setView(*_pair.second->GetView());
		// je draw tous les éléments que je veux
		for (const pair<u_int, RenderData>& _renderPair : allRendersData)
		{
			if (_isFirst && _renderPair.second.type == Screen)
			{
				// Je l'ajoute comme à afficher plus tard
				_renderWidgets.push_back(_renderPair.second);
				continue;
			}
			_renderPair.second.callback(_window);
		}
		_isFirst = false;
	}

	_window.setView(_window.getDefaultView());

	for (const RenderData& _renderData : _renderWidgets)
	{
		_renderData.callback(_window);
	}
}