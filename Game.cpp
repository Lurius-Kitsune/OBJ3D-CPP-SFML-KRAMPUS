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
    Spawner* _spawner = new Spawner();
    _spawner->Spawn(SubClassOf<MeshActor>(5.0f, 30, "", IntRect()));
    window.create(VideoMode({ 800, 600 }), "SFML works!");
    //M_SOUND.PlaySound("openDoor", WAV);

    new Timer<Seconds>([&]()
        {
            TM_Seconds& _timer = M_TIMER(Seconds);
            const float _deltaTime = _timer.GetDeltaTime().asSeconds();
            LOG(Display, "DeltaTime => " + to_string(_deltaTime));
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
    
    for (pair<u_int, OnRenderWindow> _render : onRenderWindow)
    {
        _render.second(window);
    }

    for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
    {
        if (MeshActor* _meshActor = dynamic_cast<MeshActor*>(_actor))
        {
            //window.draw(*_meshActor->GetShape()->GetDrawable());
        }
    }
    window.display();
}

void Game::Stop()
{
    M_ACTOR.BeginDestroy();
}
