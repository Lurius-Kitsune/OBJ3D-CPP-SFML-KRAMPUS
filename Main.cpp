#include "Game.h"
#include "GameManager.h"
#include "DuckHuntGame.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
    Logger::Reset();
}

int main()
{
    InitConfig();
    //M_GAME.Launch(new DuckHuntGame());

    // Smart Pointeur

    // 1 Seule peut pointer dessus
    //unique_ptr _uniquePtr  = make_unique<int>(5);

    //shared_ptr _sharedPtr = shared_ptr<int>(new int(5));
    //shared_ptr<int> _sharedPtr2 = make_shared<int>(int(5));

    //_sharedPtr2.use_count(); // Affiche le nombre d'utilisation ??

    //est shared, mais qui n'est pas comptabilisé comme utilisant un pointeur?
    /*weak_ptr _weakPtr; */


   /* RenderWindow _window(VideoMode({ 200,200 }), "SFML works");

    const Vector2f& _size = Vector2f(50.0f, 50.0f);
    const Vector2f & _position = Vector2f(_window.getSize()) / 2.0f - _size / 2.0f;

    const vector<Vertex>& _vertices =
    {
        {Vector2f(_position.x, _position.y), Color::Red},
        {Vector2f(_position.x + _size.x, _position.y), Color::Blue},
        {Vector2f(_position.x + _size.x, _position.y + _size.y), Color::Green},
        {Vector2f(_position.x, _position.y + _size.y), Color::Red},
        {Vector2f(_position.x, _position.y), Color::Blue},
        {Vector2f(_position.x + _size.x, _position.y + _size.y), Color::Green},
        {Vector2f(_position.x + _size.x, _position.y), Color::Red},
        {Vector2f(_position.x, _position.y + _size.y), Color::Blue},
    };

    while (_window.isOpen())
    {
        while (const optional _event = _window.pollEvent())
        {
            if (const auto* _resize = _event->getIf<Event::Resized>())
            {
                LOG(Display, "New size : x : " + to_string(_resize->size.x) + " y :" + to_string(_resize->size.y));
                
                const int _newX = _resize->size.x > CAST(int, _size.x + _position.x) ? _resize->size.x : CAST(int, _size.x + _position.x);
                const int _newY = _resize->size.y > CAST(int, _size.y + _position.y) ? _resize->size.y : CAST(int, _size.y + _position.y);

                _window.setSize(Vector2u(_newX, _newY));
            }
        }

        _window.clear(Color::White);
        _window.draw(_vertices.data(), _vertices.size(), PrimitiveType::TriangleStrip);
        _window.display();
    }*/

    return EXIT_SUCCESS;
}