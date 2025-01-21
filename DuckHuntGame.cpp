#include "DuckHuntGame.h"
#include "Level.h"
#include "TimerManager.h"

DuckHuntGame::DuckHuntGame()
{
	background = new MeshActor(Vector2f(), "farmBackground");
	duck = nullptr;
}

DuckHuntGame::~DuckHuntGame()
{
	delete background;
}

void DuckHuntGame::Start()
{
	Super::Start();
	Level::SpawnActor(MeshActor(Vector2f(719.0f, 400.0f), "farmBackground"));
	
	new Timer([&]()
		{
			Level::SpawnActor(MeshActor(Vector2f(50.0f, 50.0f), "duck", IntRect(Vector2i(), Vector2i(156.0f, 160.0f))));
		},
		seconds(1.0f),
		true,
		true
	);
	
	LOG(Display, "Duck Hunt Started");
}

void DuckHuntGame::Update()
{
	Super::Update();
	LOG(Display, "Duck Hunt Updated");
}

void DuckHuntGame::Stop()
{
	Super::Stop();
	LOG(Display, "Duck Hunt Stopped");
}

void DuckHuntGame::Launch()
{
	Start();
	Update();
	Stop();
}
