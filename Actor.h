#pragma once
#include "Core.h"
#include "ShapeObject.h"
#include "Component.h"

class Actor : public Core
{
	ShapeObject* shape;
	set<Component*> components;

public:
	FORCEINLINE ShapeObject* GetShape() const
	{
		return shape;
	}

	FORCEINLINE void SetShape(ShapeObject* _shape)
	{
		shape = _shape;
	}

public:
	Actor();
	Actor(const float _radius = 0.0f, const string& _path = "",
		const size_t& _pointCount = 30, const IntRect& _rect = IntRect());
	Actor(const Vector2f& _size, const string& _path = "", const IntRect& _rect = IntRect());
	~Actor();

public:
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

