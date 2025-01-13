#include "Game.h"
#include "ActorManager.h"


Game::Game()
{
	window = RenderWindow();
    new Actor(20.0f, "Cow");
    Actor* _actor = new Actor(50.0f, "Cow");
    _actor->GetShape()->Move({ 0.0f, 50.0f });
}

Game::~Game()
{

}

void Game::Launch()
{
    Start();
    Update();
}

void Game::Start()
{
    window.create(VideoMode({ 800, 600 }), "SFML works!");
}

void Game::Update()
{
	while (window.isOpen())
	{
        while (const std::optional _event = window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                Stop();
            }
        }

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
