#include "DuckHuntGame.h"
#include "Logger.h"
#include "AudioManager.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();
    Game::GetInstance().Launch();

    M_AUDIO.PlaySample<Music>("fight", MP3);

    //DuckHuntGame _game;
    //_game.Launch();
	return EXIT_SUCCESS;
}