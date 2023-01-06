#include "game.hpp"

game::game(sf::RenderWindow* window)
 :  m_window(window), m_player2(sf::Keyboard::W, sf::Keyboard::S), m_pause(true)
{
    // init players objects
    m_player1.setPosition({15.0f, 325.0f});
    m_player2.setPosition({1165.0f, 325.0f});
    m_player1.setFillColor(sf::Color::Red);
    m_player2.setFillColor(sf::Color::Blue);
}

game::~game()
{
    m_window = nullptr;
}

void game::update(float dt)
{
    m_ball.update(dt);
    m_player1.update(dt);
    m_player2.update(dt);
}

void game::collision()
{
    float force = 200.0f;
    sf::Vector2f pos_ball = m_ball.getPosition();
    sf::Vector2f pos_plr = m_player1.getPosition();
    // checking collision between ball and player1
    if((pos_ball.x <= pos_plr.x+20)&&
        (pos_ball.y >= pos_plr.y)&&
        (pos_ball.y <= pos_plr.y+150))
        m_ball.apply_force({force, m_player1.get_direction()*force});
    // checking collision between ball and player2
    pos_plr = m_player2.getPosition();
    if((pos_ball.x >= pos_plr.x-20)&&
        (pos_ball.y >= pos_plr.y)&&
        (pos_ball.y <= pos_plr.y+150))
        m_ball.apply_force({-force, m_player2.get_direction()*force});
}

void game::control()
{
    // press Space for start game
    if(m_pause)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            m_ball.apply_force({100, 0});
            m_pause = false;
        }
    // press R for restart game
    if(!m_pause)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::R))
        {
            m_ball.restart();
            m_pause = true;
        }
}

void game::draw()
{
    m_window->draw(m_player1);
    m_window->draw(m_player2);
    m_window->draw(m_ball);
}
