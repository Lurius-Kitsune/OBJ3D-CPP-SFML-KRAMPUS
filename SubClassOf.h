#pragma once
#include "Macro.h"

template <typename T>
class SubClassOf
{
	T* objectRef;

public:
	FORCEINLINE T GetObject() const
	{
		return *objectRef;
	}

public:
	template <typename ...Args>
	SubClassOf(Args... _args)
	{
		objectRef = new T(_args...);
		objectRef->Deconstruct();
	}

	~SubClassOf()
	{
		delete objectRef;
	}
};

