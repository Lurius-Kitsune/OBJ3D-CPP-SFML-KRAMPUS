#pragma once
#include "Singleton.h"
#include "Actor.h"


class Game : public Singleton<Game>
{
	RenderWindow window;
	using OnRenderWindow = function<void(RenderWindow&)>;
	map<u_int, OnRenderWindow> onRenderWindow;

	class MusicSample* music;
	class Duck* duck;
	class CameraActor* camera;

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

	FORCEINLINE void RemoveView(const View& _view)
	{
		window.setView(window.getDefaultView());
	}

public:
	Game();

protected:
	virtual void Start();
	virtual void Update();
	virtual void Stop();

public:
	virtual void Launch();
	void UpdateWindow();
};