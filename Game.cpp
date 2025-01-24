#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"

#include "MeshActor.h"
#include "Label.h"
#include "Spawner.h"
#include "Level.h"
#include "Duck.h"
#include "MusicSample.h"
#include "CameraActor.h"
#include "CircleActor.h"

Game::Game()
{
	window = RenderWindow();
}

Game::~Game()
{

}


void Game::Start()
{
    window.create(VideoMode({1400, 400}), "SFML works!");
    
    
};

void Game::Update()
{
	
}

void Game::UpdateWindow()
{
    window.clear();

    for (const pair<u_int, OnRenderWindow>& _renderPair : onRenderWindow)
    {
        _renderPair.second(window);
    }

    window.display();
}


void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}