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

// OLD
#include <math.h>
#include <conio.h>

// Collections
#include <vector>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <random>

/// SFML
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>

#define FORCEINLINE __forceinline
#define INLINE __inline
#define Super __super
#define SLEEP(_time) sf::sleep(Time(_time))
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define STRING(value) to_string(value)
#define CAST(_type, _value) static_cast<_type>(_value)


#define RESET "\033[0m"
#define RED "\x1B[38;5;196m"
#define LIGHT_BLUE "\x1B[38;5;12m"
#define ORANGE "\x1B[38;5;208m"


using namespace sf;
using namespace std;

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