#include "MeshActor.h"
#include "Game.h"

MeshActor::MeshActor(const float _radius, const size_t& _pointCount,
	const string& _path, const IntRect& _rect)
{
	mesh = CreateComponent<MeshComponent>(_radius, _path, _pointCount, _rect);
	renderMeshToken = -1;

///	renderMeshToken = M_GAME.BindOnRenderWindow(bind(&MeshActor::RenderMesh, this, placeholders::_1));
}

MeshActor::MeshActor(const Vector2f& _size, const string& _path, const IntRect& _rect)
{
	mesh = CreateComponent<MeshComponent>(_size, _path, _rect);
	renderMeshToken = -1;
	//renderMeshToken = M_GAME.BindOnRenderWindow(bind(&MeshActor::RenderMesh, this, placeholders::_1));
}

MeshActor::MeshActor(const MeshActor& _other)
{
	mesh = CreateComponent<MeshComponent>(_other.mesh);
	renderMeshToken =_other.renderMeshToken;
}

MeshActor::~MeshActor()
{
	M_GAME.UnbindOnRenderWindow(renderMeshToken);
}

void MeshActor::Deconstruct()
{
	Super::Deconstruct();
	M_GAME.UnbindOnRenderWindow(renderMeshToken);
}

void MeshActor::Construct()
{
	Super::Construct();
	M_GAME.BindOnRenderWindow(bind(&MeshActor::RenderMesh, this, placeholders::_1));
}

void MeshActor::RenderMesh(RenderWindow& _window)
{
	_window.draw(*mesh->GetShape()->GetDrawable());
}
