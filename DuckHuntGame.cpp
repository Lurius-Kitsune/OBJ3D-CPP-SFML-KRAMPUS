#include "DuckHuntGame.h"
#include "Level.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"

#include "MeshActor.h"
#include "Label.h"
#include "Spawner.h"
#include "Level.h"
#include "Duck.h"
#include "MusicSample.h"
#include "CameraActor.h"
#include "CircleActor.h"

DuckHuntGame::DuckHuntGame() : Game()
{
	//background = new MeshActor();
	duck = nullptr;
}

DuckHuntGame::~DuckHuntGame()
{
	delete background;
}


void DuckHuntGame::Start()
{
	Super::Start();

    //Level::SpawnActor(MeshActor(Vector2f(463.0f, 260.0f) * 2.0f, "background", JPG));
    music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));
    //camera = Level::SpawnActor(CameraActor({}, { 500.0f, 400.0f }));

    new Timer([&]()
        {
            Duck* _duck = Level::SpawnActor(/*SubclassOf(*/Duck(Vector2f(50.0f, 50.0f), "Duck")/*)*/);
            duckList.push_back(_duck);

            _duck->SetOriginAtMiddle();

            /*for (Actor* _actor : _duck->GetChildren())
            {
                LOG(Display, _actor->GetName());
            }*/

            if (!camera->HasTarget())
            {
                camera->SetTarget(_duck);
            }
        },
        seconds(1.0f),
        false,
        true
    );

    target = Level::SpawnActor(Duck(Vector2f(50.0f, 50.0f), "Duck"));
    target->SetPosition(Vector2f(window.getSize().x / 2, window.getSize().y / 2));
    target->SetOriginAtMiddle();
    target->SetPosition({
        window.getSize().x * 0.8f,
        window.getSize().y * 0.8f
        });

    duck = Level::SpawnActor(Duck(Vector2f(50.0f, 50.0f), "Duck"));
    duck->SetOriginAtMiddle();
    duck->SetPosition({
        window.getSize().x * 0.2f,
        window.getSize().y * 0.2f
        });

    //TODO check
    if (MovementComponent* _movement = duck->GetComponent<MovementComponent>())
    {
        _movement->SetTarget(target);
    }
    else if (MovementComponent* _movement = duck->GetMovement())
    {
        _movement->SetTarget(target);
    }

    if (MovementComponent* _movement = target->GetMovement())
    {
        _movement->SetRotateSpeed(80.0f);
        _movement->SetTarget(duck);
    }

	LOG(Display, "DuckHuntGame::Start");
}

bool DuckHuntGame::Update()
{
    Super::Update();
	LOG(Display, "DuckHuntGame::Update");

    for (u_int _index = 0; _index < CAST(u_int, duckList.size()); )
    {
        Duck* _duck = duckList[_index];

        if (_duck->IsToDelete())
        {
            duckList.erase(duckList.begin() + _index);
            continue;
        }

        _index++;
    }

    return IsOver();
}

void DuckHuntGame::Stop()
{
	Super::Stop();
}

void DuckHuntGame::UpdateWindow()
{
    /*if (camera)
    {
        window.setView(*camera->GetView());
    }*/
	Super::UpdateWindow();
}

Duck* DuckHuntGame::RetrieveFirstDuck()
{
    if (duckList.empty()) return nullptr;

    const vector<Duck*>::iterator& _it = duckList.begin();
    Duck* _duck = *_it;
    duckList.erase(_it);

    return _duck;
}
