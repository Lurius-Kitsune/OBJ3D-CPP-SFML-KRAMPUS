#pragma once
#include "CoreMinimal.h"

class CustomException : public exception
{
	using Error = char const*;

public:

    CustomException(const Error _Message) : exception(_Message)
    {

    }

public:
    NO_DISCARD virtual Error what() const override
    {
        return Super::what();
    }
private:

    NO_DISCARD virtual Error What() const
    {
        return what();
    }
};