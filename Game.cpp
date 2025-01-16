#include "Game.h"
#include "ActorManager.h"
#include "SoundManager.h"
#include "TimerManager.h"
#include "SoundSample.h"


Game::Game()
{
    window = RenderWindow();
    Actor* _actor = new Actor({100.0f, 100.0f }, "Cow");
    _actor->GetShape()->SetOrigin({ 100.0f / 2, 100.0f / 2 });
    _actor->GetShape()->SetPosition({ 800/2, 600/2 });
}

Game::~Game()
{

}

void Game::Launch()
{
    TM_Milli& _timer = TM_Milli::GetInstance();
    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    LOG(VeryVerbose, "DeltaTime => " + to_string(_deltaTime));
    LOG(Verbose, "DeltaTime => " + to_string(_deltaTime));
    LOG(Log, "DeltaTime => " + to_string(_deltaTime));
    LOG(Display, "DeltaTime => " + to_string(_deltaTime));
    LOG(Warning, "DeltaTime => " + to_string(_deltaTime));
    LOG(Error, "DeltaTime => " + to_string(_deltaTime));
    LOG(Fatal, "DeltaTime => " + to_string(_deltaTime));
    Start();
    Update();
}

void Game::Start()
{
    window.create(VideoMode({ 800, 600 }), "SFML works!");
    SoundManager::GetInstance().PlaySound("metalPipe", WAV);
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
                Stop();
            }
        }
        const float _deltaTime = _timer.GetDeltaTime().asSeconds();
        //LOG(Display, "DeltaTime => " + to_string(_deltaTime));
        ActorManager::GetInstance().Tick(_deltaTime);
        UpdateWindow();
	}
}

void Game::UpdateWindow()
{
    window.clear();
    for (Actor* _actor : ActorManager::GetInstance().GetAllActors())
    {
        window.draw(*_actor->GetShape()->GetDrawable());
    }
    window.display();
}

void Game::Stop()
{
    window.close();
}
