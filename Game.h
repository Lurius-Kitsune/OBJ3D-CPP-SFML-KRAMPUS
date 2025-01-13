#pragma once
#include "Singleton.h"
#include "Actor.h"

class Game : public Singleton<Game>
{
	RenderWindow window;

public:
	Game();
	~Game();

public:
	void Launch();

private:
	void Start();
	void Update();
	void UpdateWindow();
	void Stop();
};

