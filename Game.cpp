#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"

#include "MeshActor.h"
#include "Label.h"
#include "Spawner.h"
#include "Level.h"
#include "Duck.h"
#include "CameraActor.h"
#include "MusicSample.h"

Game::Game()
{
	window = RenderWindow();
    
}


void Game::Start()
{
    window.create(VideoMode({800, 600}), "SFML works!");
	duckCam = Level::SpawnActor(CameraActor({200.0F, 200.0f}, {800, 800 }));
	camBase = Level::SpawnActor(CameraActor({ 400.0F, 300.0f }, { 800, 600 }));
    Level::SpawnActor(MeshActor(Vector2f(463.0f, 260.0f) * 2.0f, "background", JPG));
    //music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));
	
    new Timer([&]()
        {
            Duck* _duck = Level::SpawnActor(/*SubclassOf(*/Duck(Vector2f(50.0f, 50.0f), "Duck")/*)*/);
            M_AUDIO.PlaySample<SoundSample>("couin", WAV);
            if (!duckCam->GetTarget())
            {
                duckCam->SetTarget(_duck);
            }
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
            else if (const Event::KeyPressed* _keyPressed = _event->getIf<sf::Event::KeyPressed>())
            {
                if (_keyPressed->code == Keyboard::Key::Space)
                {
                    isUsingDuckCam = !isUsingDuckCam;
                }
            }
        }

        const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        M_ACTOR.Tick(_deltaTime);
	}
}

void Game::UpdateWindow()
{
    // TODO CHECK TO DRAW AFTER CLEAR
	if (isUsingDuckCam)
	{
		window.setView(*duckCam->GetView());
	}
	else
	{
		window.setView(*camBase->GetView());
	}
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