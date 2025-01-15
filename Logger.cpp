#include "Logger.h"

Logger::Logger()
{

}

void Logger::PrintLog(const VerbosityType& _type,const string& _text, const string& _debug)
{
	if (WRITE_IN_LOG(_type))
	{
		const VerbosityData& _verbosity = VerbosityData(_type, _text, _debug);
		
		WriteInLogs(_verbosity.GetFullText(false, true));
		if (WRITE_IN_CONSOLE(_type))
		{
			WriteInConsole(_verbosity.GetFullText(true, true));
		}
	}
}

void Logger::WriteInLogs(const string& _text)
{
	ofstream _stream = ofstream("Logs.txt", ios_base::app);

	_stream << _text << endl;
}

void Logger::WriteInConsole(const string& _text)
{
	cout << _text << endl;
}
