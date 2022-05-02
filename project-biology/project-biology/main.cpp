#include "front-end.h"

int main()
{
    sf::RenderWindow window{ {1920, 990}, "Ecosystem Symolation" };

    tgui::Gui gui{ window };

    bool start = false;

    unsigned short int days = 1;
    std::string mouth = "January";
    std::string season = "Winter";
    int temp = 1;

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

            simulation(start, days, mouth, season, temp);

            window.clear();

            gui.draw();

            window.display();
        }
}