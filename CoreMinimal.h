#pragma once
#pragma warning(disable: 4275)



// STL
#include <iostream>
#include <string>
#include <fstream>
#include <functional>
#include <typeindex>
#include <typeinfo>
#include "Colors.h"

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

// Perso

#define FORCEINLINE __forceinline
#define INLINE __inline
#define Super __super
#define __FILENAME__ (strrchr(__FILE__, '\\') ? strrchr(__FILE__, '\\') + 1 : __FILE__)
#define SLEEP(_time) sf::sleep(Time(_time))
#define new new(_NORMAL_BLOCK, __FILE__, __LINE__)
#define STRING(value) to_string(value)
#define CAST(_type, _value) static_cast<_type>(_value)


#define ACTORMANAGER ActorManager::GetInstance()
#define ACTORMANAGER ActorManager::GetInstance()
#define SOUNDMANAGER SoundManager::GetInstance()
#define TIMERMANAGER TimerManager<DurationType>::GetInstance()
#define TM_SECONDS TM_Seconds::GetInstance()
#define TM_MILLI TM_Milli::GetInstance()
#define TM_MICRO TM_Micro::GetInstance()
#define GAME Game::GetInstance()	
#define TEXTUREMANAGER TextureManager::GetInstance()

#include "Logger.h"

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

