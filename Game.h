#pragma once
#include "Singleton.h"
#include "Actor.h"

class Game : public Singleton<Game>
{
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

public:
	Game();
	~Game();

protected :
	virtual void Start();
	virtual void Update();
	virtual void Stop();

public:
	virtual void Launch();
	void UpdateWindow();
};