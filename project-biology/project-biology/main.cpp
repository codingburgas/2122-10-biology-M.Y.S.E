#include "front-end.h"

int main()
{
    sf::RenderWindow window{ {1920, 990}, "Ecosystem Symolation" };

    tgui::Gui gui{ window };

    bool start = false;

    if (runExample(gui, start))
        gui.mainLoop();
}