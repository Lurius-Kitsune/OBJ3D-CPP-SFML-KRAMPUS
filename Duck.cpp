#include "Duck.h"
#include "Level.h"
#include "TimerManager.h"

Duck::Duck(const Vector2f& _size, const string& _path, const IntRect& _rect)
	: MeshActor(_size, _path, _rect)
{
	lifeSpan = 2.0f;
	movement = CreateComponent<MovementComponent>();
}

Duck::Duck(const Duck& _duck) : MeshActor(_duck)
{
	lifeSpan = _duck.lifeSpan;
	movement = CreateComponent<MovementComponent>(*_duck.movement);
}

void Duck::BeginPlay()
{
	Super::BeginPlay();

	LOG(Display, "coinc");

	new Timer([&]() { Destroy(); }, seconds(lifeSpan), true);
}
