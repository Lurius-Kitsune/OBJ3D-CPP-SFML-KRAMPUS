#include "CoreMinimal.h"
#include "TextureManager.h"
#include "ShapeObject.h"

void InitConfig()
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Detection de fuite de mémoire
}

void UpdateWindow(RenderWindow& _window, ShapeObject* _shape)
{
    _window.clear();
    _window.draw(*_shape->GetDrawable());
    _window.display();
}

void Demo()
{
    // Crée une fenêtre avec une taille et un titre
    // Fenetre de rendu
    // Plusieur mode de rendu
    RenderWindow _window(VideoMode({ 200, 200 }), "SFML works!");

    ShapeObject* _shape = new ShapeObject(100.f);
    Texture _texture;

    TextureManager::GetInstance().Load(_shape, "Cow");

    while (_window.isOpen())
    {
        while (const std::optional _event = _window.pollEvent())
        {
            if (_event->is<Event::Closed>())
            {
                _window.close();
            }
        }

        UpdateWindow(_window, _shape);
    }
    delete _shape;
}

int main()
{
    InitConfig();

    Demo();

    return EXIT_SUCCESS;
}