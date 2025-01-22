#include "Game.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"

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
    M_CAMERA.Destroy();
}


void Game::Start()
{
    window.create(VideoMode({800, 600}), "SFML works!");
    Camera* _main = new Camera(&window, "main", FloatRect({ 0,0 },{ 400, 300 }));
    SetCamera(_main);
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

    MeshActor* _n = new MeshActor(Vector2f(719.0f, 400.0f), "farmBackground");
    _n->Construct();

    MeshActor* _duck = new Duck(Vector2f(50.0f, 50.0f), "duck");
    _duck->Construct();
    _duck->AddChild(_main);
    _main->SetPosition(_duck->GetPosition());

  /*  SubclassOf<Duck> _duckRef = SubclassOf<Duck>(Duck(Vector2f(50.0f, 50.0f), "duck"));
    //Level::SpawnActor(Duck(Vector2f(50.0f, 50.0f), "duck"));

    //pitchFactor = 0.1f;
    new Timer([&]()
        {
            //Level::SpawnActor(SubclassOf<Duck>(Duck(Vector2f(50.0f, 50.0f), "duck")));
            Level::SpawnActor(_duckRef);

        },
        seconds(3.0f),
        true,
        true
    );*/
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
    if (M_CAMERA.GetCurrentCamera())
    {
        window.setView(M_CAMERA.GetCurrentCamera()->GetView());
    }
    else 
    {
        LOG(Warning, "No camera set !");
        window.setView(window.getDefaultView());
    }
    window.display();
}

void Game::SetCamera(Camera* _camera)
{
    M_CAMERA.SetCurrentCamera(_camera);
    window.setView(M_CAMERA.GetCurrentCamera()->GetView());
}

void Game::SetCamera(const string& _cameraName)
{
    SetCamera(M_CAMERA.GetCamera(_cameraName));
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