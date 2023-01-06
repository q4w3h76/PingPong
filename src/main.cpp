#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({1200, 800}), "Ping Pong",
                            sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(60);

    game game(&window);
    // created sf::Clock for calculation delta time
    sf::Clock clock;
    // main loop
    while (window.isOpen())
    {
        float dt = clock.restart().asSeconds();
        // events loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            if(event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    window.close();
        }
        // updating all game objects
        game.update(dt);
        // checked collision
        game.collision();
        // control game
        game.control();

        window.clear();
        // drawing all game objects
        game.draw();
        window.display();
    }

    return 0;
}
