#include "Game.h"
#include "ActorManager.h"
#include "TriangleActor.h"
#include "SquareActor.h"
#include "CircleActor.h"
#include "SoundManager.h"
#include "TimerManager.h"
#include "SoundSample.h"
#include "TextureManager.h"
#include "RectangleActor.h"
#include "ShapeObject.h"
#include "ShapeSpawner.h"
#include "MovementComponent.h"
#include "MoveAroundComponent.h"
#include "RotateComponent.h"
#include "SpawnComponent.h"


Game::Game()
{
    window = RenderWindow();
}

Game::~Game()
{

}

void Game::Launch()
{
    vector<string> _textureDatabase =
    {
        "Cow",
        "blob",
        "thomas",
    };

    vector<function<MeshActor* (string)>> _shapeDatabase =
    {
        {[&](const string _path) { return new CircleActor(30, _path); }},
        {[&](const string _path) { return new SquareActor(30, _path); }},
        {[&](const string _path) { return new RectangleActor({ 30.0f, 30.0f }, _path); }}
    };

    ShapeSpawner* _shapeSpawner = new ShapeSpawner([&]()
        {
            MeshActor* _actor = _shapeDatabase[RandomInt(0, _shapeDatabase.size() - 1)](_textureDatabase[RandomInt(0, _textureDatabase.size() - 1)]);
            _actor->GetShape()->SetPosition({ static_cast<float>(RandomValue<float>(0, 800)), static_cast<float>(RandomValue<float>(0, 600)) });
            _actor->AddComponent(new MovementComponent(_actor));
            _actor->GetShape()->GetDrawable()->setFillColor(Color(RandomInt(0, 255), RandomInt(0, 255), RandomInt(0, 255)));
        }, Time(milliseconds(500)), { 50, 50 });


    //_shapeSpawner->GetShape()->SetPosition({ -100, -100 });

    SquareActor* _blackhole = new SquareActor(50.0f, "blackHole");
    _blackhole->AddComponent(new RotateComponent(_blackhole, 1));
    _blackhole->GetShape()->SetPosition({ static_cast<float>(RandomValue<float>(0, 800)), static_cast<float>(RandomValue<float>(0, 600)) });

    ShapeSpawner* _starSpawner = new ShapeSpawner([&]()
        {
            SquareActor* _actor = new SquareActor(10.0f, "star");
            _actor->GetShape()->SetPosition({ static_cast<float>(RandomValue<float>(0, 800)), static_cast<float>(RandomValue<float>(0, 600)) });
            _actor->AddComponent(new MoveAroundComponent(_actor, _blackhole));
            _actor->GetShape()->GetDrawable()->setFillColor(Color(RandomInt(0, 255), RandomInt(0, 255), RandomInt(0, 255)));
        }, Time(seconds(1)), { 50, 50 });

    Start();
    Update();
}

void Game::Start()
{
    window.create(VideoMode({ 800, 600 }), "SFML works!");
    M_SOUND.PlaySound("openDoor", WAV);
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
                Stop();
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
    window.close();
}
