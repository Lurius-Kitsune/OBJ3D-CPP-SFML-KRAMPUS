#pragma once
#include "Singleton.h"
#include "Game.h"
class GameManager : public Singleton<GameManager>
{
	Game* currentGame;

public:

	~GameManager();

public:
	FORCEINLINE Game* GetCurrent() const
	{
		return currentGame;
	}

public:
	virtual void Launch(Game* _currentGame);
};

