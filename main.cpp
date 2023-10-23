#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#define FMT_HEADER_ONLY
#include <fmt/format.h>

#include "ship.hpp"

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 2;
    sf::RenderWindow window(sf::VideoMode::getDesktopMode(), "SDP", sf::Style::Fullscreen, settings);
    // window.setVerticalSyncEnabled(true);
    sf::View main_view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));

    ship players_ship;

    sf::Clock clock;
    float delta_time;
    for(;window.isOpen(); delta_time = clock.restart().asSeconds())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                return 0;
            }
        }

        //NOT WORK if ur usking   using namespace sf::Keyboard  
        /*control assumes that you can turn on the opposite engines*/
        players_ship.input_move_direction = {
            sf::Keyboard::isKeyPressed(sf::Keyboard::D),// right,
            sf::Keyboard::isKeyPressed(sf::Keyboard::A),// left,
            sf::Keyboard::isKeyPressed(sf::Keyboard::W),// up,
            sf::Keyboard::isKeyPressed(sf::Keyboard::S),// down,
            sf::Keyboard::isKeyPressed(sf::Keyboard::Q),// turn_left,
            sf::Keyboard::isKeyPressed(sf::Keyboard::E) // turn_right
        };
        players_ship.update(delta_time);
        window.draw(players_ship);

        // main_view.setCenter(players_ship.getPosition());        
        window.setView(main_view);
        window.display();
        // window.clear();
    }
    return 0;    
}