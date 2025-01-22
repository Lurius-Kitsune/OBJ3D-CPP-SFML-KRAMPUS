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
    M_AUDIO.PlaySample<MusicSample>("fight", MP3);
    Game::GetInstance().Launch();


    //DuckHuntGame _game;
    //_game.Launch();
	return EXIT_SUCCESS;
}