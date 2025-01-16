#pragma once
#pragma warning(disable: 4275)



// STL
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <typeindex>
#include <typeinfo>
#define _USE_MATH_DEFINES
#include <cmath>
#include <random>

// OLD
#include <conio.h>
#include <math.h>

// Collections
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>

/// SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

// Perso

#define FORCEINLINE __forceinline
#define INLINE __inline
#define Super __super
#define NO_DISCARD [[nodiscard]]
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define SLEEP(_time) sf::sleep(Time(_time))
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define STRING(value) to_string(value)
#define CAST(_type, _value) static_cast<_type>(_value)


// Debugs
enum VerbosityLevel
{
	VL_LOG,
	VL_WARNING,
	VL_ERROR
};

using namespace sf;
using namespace std;

typedef unsigned int u_int;
typedef unsigned short u_short;
typedef long long l_long;

typedef unsigned int u_int;
typedef unsigned short u_short;
typedef long long l_long;

static int RandomInt(const int _min, const int _max)
{
    std::random_device _dev;
    std::mt19937 _rng(_dev());
    std::uniform_int_distribution<std::mt19937::result_type> _dist(_min, _max);

    return _dist(_rng);
}

template<typename ReturnValue>
static int RandomValue(const ReturnValue _min, const ReturnValue _max)
{
    std::random_device _dev;
    std::mt19937 _rng(_dev());
    std::uniform_real_distribution<> _dist(_min, _max);

    return _dist(_rng);
}