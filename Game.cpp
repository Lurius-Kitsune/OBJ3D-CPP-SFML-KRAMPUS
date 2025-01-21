#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "SoundManager.h"

#include "MeshActor.h"
#include "Label.h"
#include "Spawner.h"
#include "Level.h"

Game::Game()
{
	window = RenderWindow();
}
Game::~Game()
{

}


void Game::Start()
{
    window.create(VideoMode({800, 600}), "SFML works!");
    //SoundSample* _sample = SoundManager::GetInstance().PlaySound("hugooo");
    //_sample->SetLoop(true);
    //new Label("Bonjour !", "Cheese_Market", TTF);

    Level::SpawnActor<Spawner>();

    /*
    MeshActor _meshActorObject = MeshActor(20.0f, 30, "Charm");
    SubclassOf<MeshActor> _meshActorRef = SubclassOf<MeshActor>(&_meshActorObject);
    MeshActor* _meshActor = Level::SpawnActor<MeshActor>(_meshActorRef);
    */

    //_spawner->Spawn(SubclassOf<Actor>());
    //_spawner->Spawn(SubclassOf<MeshActor>(20.0f, 30, "Charm"));

    /*const FloatRect& _bb1 = _mesh1->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();
    const FloatRect& _bb2 = _mesh2->GetMesh()->GetShape()->GetDrawable()->getGlobalBounds();

    if (const optional<FloatRect>& _intersection = _bb1.findIntersection(_bb2))
    {
        LOG(Display, to_string(_intersection.value().getCenter().x)
           + " / " + to_string(_intersection.value().getCenter().y));
    }*/

    M_ACTOR.BeginPlay();
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