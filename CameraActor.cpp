#include "CameraActor.h"
#include "Game.h"

CameraActor::CameraActor()
{
	camera = CreateComponent<CameraComponent>();
}

CameraActor::CameraActor(const Vector2f& _start, const Vector2f& _size)
{
	camera = CreateComponent<CameraComponent>(_start, _size);
}

CameraActor::CameraActor(const FloatRect& _rect)
{
	camera = CreateComponent<CameraComponent>(_rect);
}

CameraActor::CameraActor(const CameraActor& _other)
{
	camera = CreateComponent<CameraComponent>(_other.camera);
}

CameraActor::~CameraActor()
{
	//delete camera;
}

void CameraActor::Construct()
{
	Super::Construct();
	M_GAME.SetView(*camera->GetView());
}

void CameraActor::Deconstruct()
{
	Super::Deconstruct();
	M_GAME.RemoveView(*camera->GetView());
}

void CameraActor::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (!target || target->IsToDelete()) return;
	SetPosition(target->GetPosition());
}
