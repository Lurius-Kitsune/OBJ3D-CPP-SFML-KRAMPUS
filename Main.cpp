#include "CoreMinimal.h"
#include "ShapeSpawner.h"
#include "MovementComponent.h"
#include "MoveAroundComponent.h"
#include "BlackHole.h"
#include "Star.h"
#include "Game.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire

}

int main()
{
    InitConfig();

    vector<string> _textureDatabase =
    {
        "Cow",
        "blob",
        "thomas",
    };

    vector<function<Actor*(string)>> _shapeDatabase =
    {
        {[&](const string _path) { return new Actor(30, _path, 3); }},
        {[&](const string _path) { return new Actor(30, _path, 4); }},
        {[&](const string _path) { return new Actor({ 30.0f, 30.0f }, _path); }}
    };

    ShapeSpawner* _shapeSpawner = new ShapeSpawner([&]()
        {
            Actor* _actor = _shapeDatabase[RandomInt(0, _shapeDatabase.size() - 1)](_textureDatabase[RandomInt(0, _textureDatabase.size() -1)]);
            _actor->GetShape()->SetPosition({ static_cast<float>(RandomValue<float>(0, 800)), static_cast<float>(RandomValue<float>(0, 600)) });
            _actor->AddComponent(new MovementComponent(_actor));
            _actor->GetShape()->GetDrawable()->setFillColor(Color(RandomInt(0, 255), RandomInt(0, 255), RandomInt(0, 255)));
        }, Time(milliseconds(200)), {50, 50}, {50, 50});

    _shapeSpawner->GetShape()->SetPosition({ -100, -100 });

    BlackHole* _blackhole = new BlackHole(50.0f);
    _blackhole->GetShape()->SetPosition({ 800 / 2, 600 / 2 });

    ShapeSpawner* _starSpawner = new ShapeSpawner([&]()
        {
            Star* _actor = new Star(10.0f);
            _actor->GetShape()->SetPosition({ static_cast<float>(RandomValue<float>(0, 800)), static_cast<float>(RandomValue<float>(0, 600)) });
            _actor->AddComponent(new MoveAroundComponent(_actor, _blackhole));
            _actor->GetShape()->GetDrawable()->setFillColor(Color(RandomInt(0, 255), RandomInt(0, 255), RandomInt(0, 255)));
        }, Time(milliseconds(200)), { 50, 50 }, { 50, 50 });


    /*Star* _actor = new Star(20.0f);
    _actor->GetShape()->SetPosition({ static_cast<float>(RandomValue<float>(0, 800)), static_cast<float>(RandomValue<float>(0, 600)) });
    _actor->AddComponent(new MoveAroundComponent(_actor, _blackhole));
    _actor->GetShape()->GetDrawable()->setFillColor(Color(RandomInt(0, 255), RandomInt(0, 255), RandomInt(0, 255)));*/

    Game::GetInstance().Launch();

    return EXIT_SUCCESS;
}

