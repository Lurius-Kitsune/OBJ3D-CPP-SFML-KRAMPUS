#pragma once
#include "Core.h"
#include "RootComponent.h"
#include "Component.h"

class Actor : public Core
{
	set<Component*> components;
	RootComponent* transform;

public:
	Actor();
	virtual ~Actor();

public:
	FORCEINLINE virtual bool IsValid(Core* _core) const override
	{
		return Super::IsValid(_core);
	}

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

