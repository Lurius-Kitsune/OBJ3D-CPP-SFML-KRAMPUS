#pragma once
#include "Core.h"
#include "TransformableModifier.h"
#include "TransformableViewer.h"
#include "Component.h"
#include "RootComponent.h"

class Actor : public Core, public ITransformableModifier, public ITransformableViewer
{
	bool isToDelete;
	set<Component*> components;
	RootComponent* root;

protected:
	template <typename T, typename ...Args>
	FORCEINLINE T* CreateComponent(Args... _args)
	{
		T* _component = new T(this, _args...);
		AddComponent(_component);

		return _component;
	}

public:
	FORCEINLINE void SetToDelete()
	{
		isToDelete = true;
	}
	FORCEINLINE bool IsToDelete() const
	{
		return isToDelete;
	}
	#pragma region Transformable

	#pragma region Viewer

	FORCEINLINE virtual Vector2f GetOrigin() const override
	{
		return root->GetOrigin();
	}
	FORCEINLINE virtual Vector2f GetPosition() const override
	{
		return root->GetPosition();
	}
	FORCEINLINE virtual Angle GetRotation() const override
	{
		return root->GetRotation();
	}
	FORCEINLINE virtual Vector2f GetScale() const override
	{
		return root->GetScale();
	}
	FORCEINLINE virtual TransformData GetTransform() const override
	{
		return root->GetTransform();
	}

	#pragma endregion

	#pragma region Modifier

	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		root->SetPosition(_position);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _rotation) override
	{
		root->SetRotation(_rotation);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		root->SetScale(_scale);
	}
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		root->SetOrigin(_origin);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		root->Move(_offset);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		root->Rotate(_angle);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		root->Scale(_factor);
	}

	#pragma endregion

	#pragma endregion

public:
	Actor();
	Actor(const Actor& _actor);
	virtual ~Actor();

public:
	virtual void Construct();
	virtual void Deconstruct();
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;

	void Destroy();

	#pragma region Components

	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
	template <typename T>
	T GetComponent()
	{
		for (Component* _component : components)
		{
			if (is_same_v<decltype(_component), T>)
			{
				return dynamic_cast<T>(_component);
			}
		}

		return nullptr;
	}

	#pragma endregion
};