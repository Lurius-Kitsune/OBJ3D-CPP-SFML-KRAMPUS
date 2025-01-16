#include "LoggerException.h"

LoggerException::LoggerException(const char* _msg, const VerbosityType& _verbosity)
{
	message = _msg;
	verbosity = _verbosity;
}

LoggerException::~LoggerException() throw()
{
}

char const* LoggerException::what() const
{
	cerr << Logger::GetLogMessage(verbosity, message) << endl;
	return "";
}

