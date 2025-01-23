#include "CameraActor.h"
#include "Game.h"

CameraActor::CameraActor()
{
	duckCam = CreateComponent<CameraComponent>();
	target = nullptr;
}

CameraActor::CameraActor(const Vector2f& _start, const Vector2f& _size)
{
	duckCam = CreateComponent<CameraComponent>(_start, _size);
	target = nullptr;
}

CameraActor::CameraActor(const FloatRect& _rect)
{
	duckCam = CreateComponent<CameraComponent>(_rect);
	target = nullptr;
}

CameraActor::CameraActor(const CameraActor& _other)
{
	duckCam = CreateComponent<CameraComponent>(_other.duckCam);
	target = _other.target;
}

CameraActor::~CameraActor()
{
	//delete duckCam;
}

void CameraActor::Construct()
{
	Super::Construct();
	M_GAME.SetView(*duckCam->GetView());
}

void CameraActor::Deconstruct()
{
	Super::Deconstruct();
	M_GAME.RemoveView(*duckCam->GetView());
}

void CameraActor::Tick(const float _deltaTime)
{
	Super::Tick(_deltaTime);
	if (!target || target->IsToDelete())
	{
		target = nullptr;
		return;
	};
	SetPosition(target->GetPosition());
}
