#include "front-end.h"

int main()
{
    sf::RenderWindow window{ {1920, 990}, "Ecosystem Simolation" };

    tgui::Gui gui{ window };

    bool start = false;

    if (runExample(gui, start))
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                gui.handleEvent(event);

                if (event.type == sf::Event::Closed)
                    window.close();
            }

            simulation(start);

            window.clear();

            gui.draw();

            window.display();
        }
}