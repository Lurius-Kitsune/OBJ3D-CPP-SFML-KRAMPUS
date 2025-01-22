#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"

#include "MeshActor.h"
#include "Duck.h"
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
    //SoundSample* _sample = AudioManager::GetInstance().PlaySample("hugooo");
    //_sample->SetLoop(true);
    //new Label("Bonjour !", "Cheese_Market", TTF);

    //Spawner* _spawner = Level::SpawnActor<Spawner>();

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

    Level::SpawnActor(MeshActor(Vector2f(719.0f, 400.0f), "farmBackground"));
    
    //Level::SpawnActor(MeshActor(Vector2f(463.0f, 260.0f), "duck"));

    //pitchFactor = 0.1f;
    new Timer([&]()
        {
            Level::SpawnActor(/*SubclassOf<Duck>*/(Duck(Vector2f(50.0f, 50.0f), "duck")));
        },
        seconds(3.0f),
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