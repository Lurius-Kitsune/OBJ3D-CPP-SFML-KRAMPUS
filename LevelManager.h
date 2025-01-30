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

	FORCEINLINE void SetLevel(const string& _name)
	{
		currentLevel->
	}

	FORCEINLINE void RegisterLevel(const string& _name, Level* _level)
	{
		allLevels.emplace(_name, _level);
	}
};

