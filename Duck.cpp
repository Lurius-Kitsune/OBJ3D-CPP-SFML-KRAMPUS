#include "Duck.h"
#include "Level.h"
#include "TimerManager.h"

Duck::Duck(const Vector2f& _size, const string& _path, const IntRect& _rect)
	: MeshActor(_size, _path, _rect)
{
	lifeSpan = 5.0f;
	movement = CreateComponent<MovementComponent>();
	//animation = CreateComponent<AnimationComponent>();

	//const SpriteData& _spriteData = { 0.2f, Vector2i(), Vector2i(80, 50) };
	//const AnimationData& _animData = AnimationData(3, 2.0f, _spriteData);
	//animation->AddAnimation(new Animation("Default", GetMesh()->GetShape(), _animData));
	//animation->SetCurrentAnimation("Default");
}

Duck::Duck(const Duck& _duck) : MeshActor(_duck)
{
	lifeSpan = _duck.lifeSpan;
	movement = CreateComponent<MovementComponent>(_duck.movement);
	//animation = CreateComponent<AnimationComponent>(_duck.animation);
}

void Duck::BeginPlay()
{
	Super::BeginPlay();

	new Timer([&]() {Destroy(true); }, seconds(lifeSpan), true);

	LOG(Display, "coinc");

} 
