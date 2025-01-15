#include "CoreMinimal.h"
#include "TextureManager.h"
#include "TimerManager.h"
#include "ShapeObject.h"
#include "Game.h"



void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

}

bool Test(const int _index)
{
    cout << "coucou x"<< _index << endl;
    return _index % 2 == 0;
}

int main()
{
    InitConfig();
    new Timer([]() { static int _index = 0; 
    if (Test(++_index)) cout << "BOB" << endl;
    }, Time(seconds(2.0f)), true, true);

    GAME.Launch();

    return EXIT_SUCCESS;
}

