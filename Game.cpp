#include "Game.h"

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
}

void Game::Start()
{
    window.create(VideoMode({ 200, 200 }), "SFML works!");
    Update();
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
    //_window.draw(*_shape->GetDrawable());
    window.display();
}

void Game::Stop()
{
    window.close();
}
