#pragma once
#include "Core.h"
#include "ShapeObject.h"
#include "Component.h"

class Actor : public Core
{
	ShapeObject* shape;
	set<Component*> components;

public:
	FORCEINLINE void SetShape(ShapeObject* _shape)
	{
		shape = _shape;
	}

public:
	Actor();
	~Actor();

public:
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

protected:
	virtual void BeginPlay() override;
	virtual void Tick(const float _deltaTime) override;
	virtual void BeginDestroy() override;
};

