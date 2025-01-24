#include "Game.h"
#include "DuckHuntGame.h"
#include "GameManager.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

float Lerp(const float _start, const float _end, const float _time)
{
    return _start + _time * (_end - _start);
}

int main()
{
    InitConfig();

    //M_GAME.Launch(new DuckHuntGame());

   

    /*DuckHuntGame _game;
    _game.Launch();*/

	return EXIT_SUCCESS;
}