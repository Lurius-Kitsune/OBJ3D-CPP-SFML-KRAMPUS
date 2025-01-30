#pragma once
#include "Singleton.h"

#include "Level.h"

class LevelManager : public Singleton<LevelManager>
{
	Level* currentLevel;
	map<string, Level*> allLevels;

public:
	FORCEINLINE Level* GetCurrentLevel() const
	{
		return currentLevel;
	}
	FORCEINLINE bool SetLevel(const string& _name)
	{
		if (!allLevels.contains(_name))
		{
			LOG(Error, "Level \"" + _name + "\"  not found");
			return false;
		}

		if(currentLevel) currentLevel->OnExit();
		currentLevel = allLevels[_name];
		currentLevel->OnLoad();

		return true;
	}
	FORCEINLINE void RegisterLevel(const string& _name, Level* _level)
	{
		allLevels.emplace(_name, _level);
	}

	FORCEINLINE void Destroy()
	{
		for (auto _it = allLevels.begin(); _it != allLevels.end(); _it++)
		{
			_it->second->OnDestroy();
			allLevels.erase(_it);
			delete _it->second;
		}
	}
};

