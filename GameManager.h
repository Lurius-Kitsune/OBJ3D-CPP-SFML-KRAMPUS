#pragma once
#include "Singleton.h"
#include "Game.h"
class GameManager : public Singleton<GameManager>
{
	Game* currentGame;

public:

	~GameManager();

public:
	FORCEINLINE Game* GetCurrentGame() const
	{
		return currentGame;
	}

public:
	virtual void Launch(Game* _currentGame);
};

