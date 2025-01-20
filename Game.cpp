#include "Game.h"
#include "Spawner.h"
#include "MeshActor.h"
#include "CircleActor.h"
#include "ActorManager.h"
#include "SoundManager.h"
#include "TimerManager.h"
#include "SoundSample.h"


Game::Game()
{
    window = RenderWindow();
}

Game::~Game()
{

}

void Game::Launch()
{
    Start();
    Update();
    Stop();
}

void Game::Start()
{
    SubClassOf<MeshActor>* _prefab = new SubClassOf<MeshActor>(5.0f, 30, "Cow", IntRect());
    Spawner<MeshActor>* _spawner = new Spawner<MeshActor>(_prefab);
    window.create(VideoMode({ 800, 600 }), "SFML works!");
    //M_SOUND.PlaySound("openDoor", WAV);

    new Timer<Seconds>([&]()
        {
            TM_Seconds& _timer = M_TIMER(Seconds);
            const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        }, Time(seconds(2.0f)), true, true);
}

void Game::Update()
{
	while (window.isOpen())
	{
        TM_Seconds& _timer = TM_Seconds::GetInstance();
        _timer.Update();
        while (const std::optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                window.close();
            }
        }
        const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        M_ACTOR.Tick(_deltaTime);
        UpdateWindow();
	}
}

void Game::UpdateWindow()
{
    window.clear();
    
    //for (pair<u_int, OnRenderWindow> _render : onRenderWindow)
    //{
    //    _render.second(window);
    //}

    for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
    {
        if (MeshActor* _meshActor = dynamic_cast<MeshActor*>(_actor))
        {
            _meshActor->RenderMesh(window);
        }
    }
    window.display();
}

void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}
