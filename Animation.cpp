#include "Animation.h"
#include "TextureManager.h"

bool LinkedAnimation::TryToChange()
{
	if (!IsValid()) return false;
	animation->Start(); // TODO
	return true;
}

Animation::Animation(const string& _name, ShapeObject* _shape, const AnimationData& _data)
{
	currentIndex = _other.currentIndex;
	name = _name;
	data = _data;
	shape = _shape;

	timer = new Timer([&]() 
		{ Update(); },
		seconds(data.sprite[currentIndex].timesBetween * data.count / data.duration),
		true,
		true
	);
}

Animation::Animation(const Animation& _other)
{
	currentIndex = _other.currentIndex;
	name = _other.name;
	data = _other.data;
	shape = _other.shape;
	timer = new Timer([&]()
		{ Update(); },
		seconds(data.sprite[currentIndex].timesBetween * data.count / data.duration),
		true,
		true
	);
}

Animation::~Animation()
{
	LOG(Display, "Animation destroyed : " + name);
	delete timer;
}

void Animation::Start()
{
	timer->Start();
}

void Animation::Resume()
{
	timer->Resume();
}

void Animation::Pause()
{
	timer->Pause();
}

void Animation::Stop()
{
	Pause();
	Reset();
}

void Animation::Update()
{
	++currentIndex;
	if (!IsValidIndex())
	{
		if (!data.canLoop)
		{
			// transition

			Stop();
			return;
		}
		else
		{
			Reset();
		}
	}
	const SpriteData& _spriteData = data.sprite[currentIndex - 1];
	const Vector2i& _start = CAST(Vector2i, _spriteData.start);
	const Vector2i& _size = CAST(Vector2i, _spriteData.size);
	M_TEXTURE.SetTextureRect(shape->GetDrawable(), _start, _size);
}

void Animation::Reset()
{
	currentIndex = 0;
	timer->Reset();
}


