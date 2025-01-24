#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"

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
    window.create(VideoMode({1400, 800}), "SFML works!");
    
    
};

bool Game::Update()
{
    TM_Seconds& _timer = M_TIMER;
    _timer.Update();

    while (const optional _event = window.pollEvent())
    {
        if (_event->is<Event::Closed>())
        {
            window.close();
        }
    }


    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    M_ACTOR.Tick(_deltaTime);

    static float _t = 0.0f;
    if (_t > 1.0f)
    {
		_t = 0.0f;
    }
    const float _value = Lerp(0.0f, 100.0f, 0.5f);
    LOG(Display, to_string(_value));
   _t += _deltaTime;

    return IsOver();
}

void Game::UpdateWindow()
{
    window.clear();
	M_CAMERA.RenderAllCameras(window);
    window.display();
}


void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}