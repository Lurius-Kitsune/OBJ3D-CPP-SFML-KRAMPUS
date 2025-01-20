#pragma once
#include "Core.h"
#include "RootComponent.h"
#include "ShapeObject.h"
#include "Component.h"
#include "ITransformableViewer.h"
#include "ITransformableModifier.h"

class Actor : public Core, public ITransformableViewer, public ITransformableModifier
{
	set<Component*> components;
	RootComponent* root;


public:
	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		//return Super::IsValid(_core);
		// TO DO ASK
		return true;
	}

	#pragma region Transformable
	#pragma region Modifier
	FORCEINLINE virtual void SetOrigin(const Vector2f& _origin) override
	{
		root->SetOrigin(_origin);
	}
	FORCEINLINE virtual void SetPosition(const Vector2f& _position) override
	{
		root->SetPosition(_position);
	}
	FORCEINLINE virtual void SetScale(const Vector2f& _scale) override
	{
		root->SetScale(_scale);
	}
	FORCEINLINE virtual void SetRotation(const Angle& _angle) override
	{
		root->SetRotation(_angle);
	}
	FORCEINLINE virtual void Move(const Vector2f& _offset) override
	{
		root->Move(_offset);
	}
	FORCEINLINE virtual void Scale(const Vector2f& _factor) override
	{
		root->Scale(_factor);
	}
	FORCEINLINE virtual void Rotate(const Angle& _angle) override
	{
		root->Rotate(_angle);
	}
	#pragma endregion

	#pragma region Viewer
	FORCEINLINE virtual TransformData GetTransform() const override
	{
		return root->GetTransform();
	}
	FORCEINLINE virtual Vector2f GetOrigin() const override
	{
		return root->GetOrigin();
	}
	FORCEINLINE virtual Vector2f GetPosition() const override
	{
		return root->GetPosition();
	}
	FORCEINLINE virtual Vector2f GetScale() const override
	{
		return root->GetScale();
	}
	FORCEINLINE virtual Angle GetRotation() const override
	{
		return root->GetRotation();
	}
	#pragma endregion

	#pragma endregion

protected:
	template <typename T, typename ...Args>
	FORCEINLINE T* CreateComponent(Args... _args)
	{
		T* _component = new T(_args...);
		AddComponent(_component);

		return _component;
	}
public:
	Actor();
	virtual ~Actor();

	#pragma region Component
	void AddComponent(Component* _component);
	void RemoveComponent(Component* _component);
	template<typename T>
	T* GetComponent()
	{
		for (Component* _component : components)
		{
			if (is_same_v<decltype(_component), T>) return dynamic_cast<T>(_component);
		}

		return nullptr;
	}
	#pragma endregion

	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;

private: 
	void Register();
};

