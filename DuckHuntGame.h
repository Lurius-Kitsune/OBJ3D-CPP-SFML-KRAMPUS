#pragma once
#include "Game.h"
#include "MeshActor.h"

class MusicSample;
class CameraActor;
class Duck;

class DuckHuntGame : public Game
{
	MeshActor* background;

	//TODO remove
	MusicSample* music;
	CameraActor* camera;
	Duck* duck;
	Duck* target;
	vector<Duck*> duckList;
	Vector2f center;
	float angle;

public:
	DuckHuntGame();
	~DuckHuntGame();

public:
	virtual void Start() override;
	virtual bool Update() override;
	virtual void Stop() override;

	virtual void UpdateWindow() override;
	Duck* RetrieveFirstDuck();
};