#include "game.hpp"
#include <iostream>
#include <ctime>
#include <cstdlib>

game::game(sf::RenderWindow* window)
 :  m_window(window), m_player2(sf::Keyboard::W, sf::Keyboard::S), m_pause(true)
{
    // init font 
    if(!m_font.loadFromFile("../res/roboto.ttf"))
        std::cerr << "can't load font from file" << std::endl;
    // init text
    m_text.setFont(m_font);
    m_text.setString("Press space bar to start game");
    m_text.setPosition({500, 300});
    // init text score
    m_text_score.setFont(m_font);
    m_text_score.setString("0:0");
    m_text_score.setPosition({580, 0});
    m_text_score.setCharacterSize(50);
    // init players objects
    m_player1.setPosition({15, 325});
    m_player2.setPosition({1165, 325});
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
    // update text score
    std::ostringstream os;
    os << m_ball.get_player1_score()
    << ":" << m_ball.get_player2_score();
    m_text_score.setString(os.str());

    m_player1.update(dt);
    m_player2.update(dt);
}

void game::collision()
{
    float force = 200;
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
    // press Space bar to start game
    if(m_pause)
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
        {
            // calculating random number for starting direction of ball
            srand(time(NULL));
            // random number is 0 or 1
            int num = rand() % 2;
            // if random number is 0, then direction of ball will be left
            m_ball.apply_force({(num == 0) ? -100 : 100, 0});
            m_pause = false;
        }
    // press R bar to restart game
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
    m_window->draw(m_text_score);
    if(m_pause)
        m_window->draw(m_text);
}
