#include "front-end.h"

int main()
{
    sf::RenderWindow window{ {1920, 1080}, "TGUI example - SFML_GRAPHICS backend" };

    tgui::Gui gui{ window };

    if (runExample(gui))
        gui.mainLoop();
}