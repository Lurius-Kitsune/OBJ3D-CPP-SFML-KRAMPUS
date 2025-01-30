#include "Level.h"
#include "LevelManager.h"

Level::Level()
{
}

void Level::OnLoad()
{

}

void Level::OnExit()
{

}

void Level::OnDestroy()
{
	actors.BeginDestroy();
}
