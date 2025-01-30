#include "Level.h"
#include "LevelManager.h"

Level::Level(const string& _name)
{
	actors = ActorManager();
	cameras = CameraManager();
	M_LEVEL.RegisterLevel(_name, this);
}

void Level::Update(const float _deltaTime)
{
	actors.Update(_deltaTime);
}

void Level::OnLoad()
{
	actors.BeginPlay();
}

void Level::OnExit()
{

}

void Level::OnDestroy()
{
	actors.BeginDestroy();
}
