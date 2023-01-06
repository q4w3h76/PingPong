#include "player.hpp"

player::player(sf::Keyboard::Key key_up, sf::Keyboard::Key key_down)
 :  RectangleShape({20, 150}), m_mass(150), m_force(30), m_key_up(key_up), m_key_down(key_down)
{}

void player::update(float dt)
{
    control();
    collision_border();
    move(m_mass.simulate(dt));
}

// private methods
void player::control()
{
    const float current_pos = getPosition().y;
    m_direction = 0;
    // move up
    if(sf::Keyboard::isKeyPressed(m_key_up))
        if(current_pos >= 0)
            m_direction = -1;
    // move down
    if(sf::Keyboard::isKeyPressed(m_key_down))
        if(current_pos <= 650)
            m_direction = 1;

    m_mass.apply_force({0, m_direction * m_force});
}

void player::collision_border()
{
    const sf::Vector2f current_pos = getPosition();
    // upper border
    if(current_pos.y <= 0)
    {
        setPosition({current_pos.x, 0});
        m_mass.restart();
        m_mass.apply_force({0, m_force});
    }
    // lower border
    if(current_pos.y >= 650)
    {
        setPosition({current_pos.x, 650});
        m_mass.restart();
        m_mass.apply_force({0, -m_force});
    }
}
