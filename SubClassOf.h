#pragma once
#include "Macro.h"

template <typename T>
class SubClassOf
{
	T* objectRef;

public:
	FORCEINLINE T& GetObject()
	{
		return *objectRef;
	}

public:
	template <typename ...Args>
	SubClassOf(Args... _args)
	{
		objectRef = new T(_args...);
	}
	~SubClassOf()
	{
		delete objectRef;
	}
};

