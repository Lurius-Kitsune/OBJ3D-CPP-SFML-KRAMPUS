#pragma once
#include <iostream>
#include "Colors.h"
//#include "TimerManager.h"
#include <vector>
#include <set>

#define DEBUG_FILE

#ifdef DEBUG_FILE
#define PATH __FILE__
#else
#define PATH __FUNCTION__
#endif

#ifdef DEBUG
#define USE_DEBUG 1
#else
#define USE_DEBUG 0
#endif

#define WRITE_IN_LOG(_verbosity) _type >= Log
#define WRITE_IN_CONSOLE(_verbosity) _type > Log

#define DEBUG_INFO  WHITE" => (" + string(PATH)  +  " | " + to_string(__LINE__) + ")"
#define LOG(_verbosity, _msg) Logger::PrintLog(_verbosity, _msg, DEBUG_INFO)


using namespace std;

enum VerbosityType
{
    VeryVerbose,
    Verbose,
    Log,
    Display,
    Warning,
    Error,
    Fatal,

    VT_COUNT
};


class VerbosityData
{
    string color;
    string prefix;
    string text;
    string debug;
    bool useDebug;

private:
    __forceinline string GetPrefix(const bool _useColor) const
    {
        string _prefix = prefix;
        if (_useColor)
        {
            _prefix = RESET "[" + color + prefix + RESET + "]";
        }
        return _prefix;
    }
public:
    __forceinline string GetFullText(const bool _useColor = true, const bool _useTime = false) const
    {
        const string& _color = _useColor ? color : "";
        const string& _time = _useTime ? "<" __TIME__ ">" : "";
        string _fullText = _time  + GetPrefix(_useColor)  + _color + text + RESET;
        if (USE_DEBUG || useDebug)
        {
            _fullText += "\n\t" + debug;
        }
        return _fullText;

    }
public:
    VerbosityData(const VerbosityType& _type, const string& _text,
        const string& _debug)
    {
        ComputeUseDebug(_type);
        ComputePrefix(_type);
        ComputeColor(_type);
        text = _text;
        debug = _debug;
    }

private:
    void ComputePrefix(const VerbosityType& _type)
    {
        if (_type == VT_COUNT)
        {
            throw exception("Exception => Invalid VerbosityType");
        }

        const vector<string>& _verbosityTexts =
        {
            "VeryVerbose",
            "Verbose",
            "Log",
            "Display",
            "Warning",
            "Error",
            "Fatal",
        };

        prefix = _verbosityTexts[_type];
    }
    void ComputeColor(const VerbosityType& _type)
    {
        if (_type == VT_COUNT)
        {
            throw exception("Exception => Invalid VerbosityType");
        }

        const vector<string>& _verbosityColors =
        {
            DARK_GRAY,
            GRAY,
            WHITE,
            BLUE,
            ORANGE,
            RED,
            BG_YELLOW RED,
        };

        color = _verbosityColors[_type];
    }
    void ComputeUseDebug(const VerbosityType& _type)
    {
        const set<VerbosityType>& _debugableVerbosity =
        {
            Warning,
            Error,
            Fatal,
        };
        useDebug = _debugableVerbosity.find(_type) != _debugableVerbosity.end();
    }
};

class Logger
{
    string logsPath;

public:
    
public:
    Logger();

public:
    static void PrintLog(const VerbosityType& _type, const string& _text, const string& _debug = "");
private:

    static void WriteInLogs(const string& _text);
    static void WriteInConsole(const string& _text);
};

