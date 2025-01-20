#pragma once
#include "Core.h"
#include "RootComponent.h"
#include "ShapeObject.h"
#include "Component.h"

class Actor : public Core
{
	set<Component*> components;
	RootComponent* transform;


public:
	FORCEINLINE virtual void Move(const Vector2f& _offset) const
	{
		transform->Move(_offset);
	}

	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		//return Super::IsValid(_core);
		// TO DO ASK
		return true;
	}

private:
	template <typename T>
	FORCEINLINE T* CreateComponent()
	{
		T* _component = new T(this);
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

