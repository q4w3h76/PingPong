#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Font.hpp>
#include "player.hpp"
#include "ball.hpp"

class game
{
    player m_player1, m_player2;
    ball m_ball;
    sf::Font m_font;
    sf::Text m_text;
    sf::Text m_text_score;
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
