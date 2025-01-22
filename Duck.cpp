#include "Duck.h"
#include "Level.h"
#include "TimerManager.h"

Duck::Duck(const Vector2f& _size, const string& _path, const IntRect& _rect)
	: MeshActor(_size, _path, _rect)
{
	lifeSpan = 5.0f;
	movement = CreateComponent<MovementComponent>();
	animation = CreateComponent<AnimationComponent>();

	Construct();
}

Duck::Duck(const Duck& _duck) : MeshActor(_duck)
{
	lifeSpan = _duck.lifeSpan;
	movement = CreateComponent<MovementComponent>(_duck.movement);
	animation = CreateComponent<AnimationComponent>();
}

void Duck::Construct()
{
	Super::Construct();

	const float _timeBetween = 0.05f;
	const Vector2i& _spriteSize = Vector2i(41, 40);
	const vector<SpriteData>& _spriteData =
	{
		{ _timeBetween, Vector2i(0,0), _spriteSize },
		{ _timeBetween, Vector2i(44,0), _spriteSize },
		{ _timeBetween, Vector2i(88,0), _spriteSize },
		{ _timeBetween, Vector2i(0,48), _spriteSize },
		{ _timeBetween, Vector2i(44,48), _spriteSize },
		{ _timeBetween, Vector2i(88,48),_spriteSize },
		{ _timeBetween, Vector2i(0,96), _spriteSize },
		{ _timeBetween, Vector2i(44,96),_spriteSize },
		{ _timeBetween, Vector2i(88,96), _spriteSize},
	};
	//const SpriteData& _spriteData = { 0.2f, Vector2i(), Vector2i(80, 50) };
	const AnimationData& _animData = AnimationData(2.0f, _spriteData);
	animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animData));
	animation->SetCurrentAnimation("Default");
	animation->StartAnimation();
}
void Duck::Deconstruct()
{
	Super::Deconstruct();

	//animation->StopAnimation();

}
void Duck::BeginPlay()
{
	Super::BeginPlay();

	new Timer([&]() {Destroy(); }, seconds(lifeSpan), true);

	LOG(Display, "coinc");

}

