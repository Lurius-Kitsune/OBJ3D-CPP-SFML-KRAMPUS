#pragma once
#include "CoreMinimal.h"

class Game
{
protected:

	RenderWindow window;

public:
	
	FORCEINLINE void SetView(const View& _view)
	{
		window.setView(_view);
	}
	FORCEINLINE void RemoveView()
	{
		window.setView(window.getDefaultView());
	}

	FORCEINLINE virtual bool IsOver() const
	{
		return !window.isOpen();
	}

public:
	Game();
	virtual ~Game();

public:
	virtual void Start();
	virtual bool Update();
	virtual void Stop();
	virtual void UpdateWindow();
};