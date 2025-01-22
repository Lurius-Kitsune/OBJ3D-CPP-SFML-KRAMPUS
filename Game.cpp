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

Game::Game()
{
	window = RenderWindow();
}


void Game::Start()
{
    window.create(VideoMode({800, 600}), "SFML works!");
    
    Level::SpawnActor(MeshActor(Vector2f(463.0f, 260.0f) * 2.0f, "background", JPG));
    //music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));

    pitchFactor = 0.1f;
    new Timer([&]()
        {
            Level::SpawnActor(/*SubclassOf(*/Duck(Vector2f(50.0f, 50.0f), "Duck")/*)*/);
            M_AUDIO.PlaySample<SoundSample>("couin", WAV);
        },
        seconds(2.0f),
        true,
        true
    );
};

void Game::Update()
{
	while (window.isOpen()) 
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
	}
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


void Game::Launch()
{
	Start();
	Update();
	Stop();
}