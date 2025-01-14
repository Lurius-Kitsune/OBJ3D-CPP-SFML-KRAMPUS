#pragma once
#pragma warning(disable: 4275)

// STL
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <typeindex>
#include <typeinfo>

// OLD
#include <math.h>
#include <conio.h>

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
