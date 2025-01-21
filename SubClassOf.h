#pragma once
#include "Macro.h"

template <typename T>
class SubClassOf
{
	T objectRef;

public:
	FORCEINLINE T GetObject() const
	{
		return *objectRef;
	}

public:
	/*SubClassOf()
	{
		objectRef = T();
	}*/
	SubClassOf(const T& _objectRef)
	{
		objectRef = new T(_objectRef);
	}
	SubClassOf(const T* _objectRef)
	{
		objectRef = new T(*_objectRef);
	}
};