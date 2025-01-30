#include "Game.h"
#include "ActorManager.h"
#include "InputManager.h"
#include "CameraManager.h"
#include "TimerManager.h"
#include "LevelManager.h"
#include "MeshActor.h"

using namespace Input;
using namespace Camera;

Game::Game()
{
	window = RenderWindow(VideoMode({600,600}), "UwU");
}


void Game::Start()
{
    Level* _test = new Level("first");

    window.create(VideoMode({ 800, 400 }), "Angry Birds");

    _test->CreateCamera("DefaultCamera");
    _test->SpawnActor(MeshActor(_test, 50.f, 30, "Cow"));

    Level* _second = new Level("second");
    _second->CreateCamera("DefaultCamera");
    MeshActor* _aa = _second->SpawnActor(MeshActor(_second, 50.f, 30, "Ball"));

    M_LEVEL.SetLevel("second");


    ActionMap* _actionMap = M_INPUT.CreateActionMap("Demo");
    /*Action* _action = new Action("Test", ActionData(Key::A, ActionType::KeyPressed), [&]() { LOG(Display, "coucou"); });
    _actionMap->AddAction(_action);
    _actionMap->Enable();*/
};

bool Game::Update()
{
    M_INPUT.Update(window);
    TM_Seconds& _timer = M_TIMER;
    _timer.Update();
    const float _deltaTime = _timer.GetDeltaTime().asSeconds();
    M_LEVEL.GetCurrentLevel()->Update(_deltaTime);

    return IsOver();
}

void Game::UpdateWindow()
{
    window.clear();
    M_LEVEL.GetCurrentLevel()->GetCameraManager().RenderAllCameras(window);
    window.display();
}

void Game::Stop()
{
    M_LEVEL.Destroy();
}