#include "DuckHuntGame.h"
#include "Level.h"
#include "ActorManager.h"
#include "TimerManager.h"
#include "AudioManager.h"
#include "CameraManager.h"

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
	//delete background;
}


void DuckHuntGame::Start()
{
	Super::Start();

    //Level::SpawnActor(MeshActor(Vector2f(463.0f, 260.0f) * 2.0f, "background", JPG));
    music = M_AUDIO.PlaySample<MusicSample>("Crab_Rave", MP3, seconds(50.0f));
    //camera = Level::SpawnActor(CameraActor({}, { 500.0f, 400.0f }));
	M_CAMERA.CreateCamera();
    const Vector2f& _start = Vector2f(100.0F, 100.0f);
    const Vector2f& _gap = Vector2f(150.0F, 150.0f);
	for (u_int _index = 0; _index < 5; _index++)
	{
        CircleActor* _shape = Level::SpawnActor(CircleActor(75.0f));
		_shape->SetPosition(_start + _gap * CAST(float, _index));
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
