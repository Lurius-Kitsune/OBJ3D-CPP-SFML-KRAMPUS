#pragma once
#include "CoreMinimal.h"

class Game
{
protected:

	RenderWindow window;
	using OnRenderWindow = function<void(RenderWindow&)>;
	map<u_int, OnRenderWindow> onRenderWindow;

public:
	FORCEINLINE u_int BindOnRenderWindow(OnRenderWindow _callback)
	{
		u_int _id = GetUniqueID();
		onRenderWindow.insert({ _id, _callback});
		return _id;
	}
	FORCEINLINE void UnbindOnRenderWindow(const u_int& _uniqueId)
	{
		onRenderWindow.erase(_uniqueId);
	}
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
	~Game();

public:
	virtual void Start();
	virtual bool Update();
	virtual void Stop();
	virtual void UpdateWindow();
};