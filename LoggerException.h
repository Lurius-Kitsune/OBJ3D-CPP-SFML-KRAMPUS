#pragma once
#include "CoreMinimal.h"

class LoggerException : public exception
{
	string message;
	VerbosityType verbosity;

public:
	LoggerException(const char* _msg, const VerbosityType& _verbosity);
	~LoggerException() throw();

public:
	_NODISCARD virtual char const* what() const override;
};

