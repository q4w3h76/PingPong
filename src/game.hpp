#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include "player.hpp"
#include "ball.hpp"

class game
{
    player m_player1, m_player2;
    ball m_ball;
    sf::RenderWindow* m_window;
    bool m_pause;
public:
    game(sf::RenderWindow* window);
    ~game();

    void update(float dt);
    // checking collision between game objects
    void collision();
    void control();
    void draw();
};

#endif // GAME_HPP
