#include "CameraManager.h"

void CameraManager::Destroy()
{
	for (auto _it = allCameras.begin(); _it != allCameras.end(); _it++)
	{
		_it->second->SetToDelete();
	}

	allCameras.clear();
}
