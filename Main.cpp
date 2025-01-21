#include "Game.h"
#include "Logger.h"
#include <algorithm>


void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

}

int main()
{
    string _text1 = ("coucou");
    string _text2 = _text1;
    cout << _text2 << endl;

    return EXIT_SUCCESS;


    InitConfig();

    M_GAME.Launch();

    return EXIT_SUCCESS;
}

