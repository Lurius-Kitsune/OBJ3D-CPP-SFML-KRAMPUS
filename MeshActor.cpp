#include "MeshActor.h"

MeshActor::MeshActor(const float _radius, const size_t& _pointCount,
	const string& _path, const IntRect& _rect)
{
	mesh = new MeshComponent(this, _radius, _path, _pointCount, _rect);
	AddComponent(mesh);
}

MeshActor::MeshActor(const Vector2f& _size, const string& _path, const IntRect& _rect)
{
	mesh = new MeshComponent(this, _size, _path, _rect);
	AddComponent(mesh);
}
