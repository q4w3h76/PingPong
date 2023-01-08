#include "ball.hpp"

ball::ball() : CircleShape(10), m_mass(25, true, 9),
                m_plr1_score(0), m_plr2_score(0)
{
    setPosition({600, 400});
}

void ball::restart()
{
    setPosition({600, 400});
    m_plr1_score = m_plr2_score = 0;
    m_mass.restart();
}

void ball::update(float dt)
{
    collision_border();
    move(m_mass.simulate(dt));
}

// private method
void ball::collision_border()
{
    const sf::Vector2f current_pos = getPosition();
    // right and left border
    if(current_pos.x <= 0)
    {
        m_plr2_score++;
        setPosition({600, 400});
        m_mass.restart();
        m_mass.apply_force({-100, 0});
    }
    if(current_pos.x >= 1200)
    {
        m_plr1_score++;
        setPosition({600, 400});
        m_mass.restart();
        m_mass.apply_force({100, 0});
    }
    // lower and upper border
    if((current_pos.y >= 800) || (current_pos.y <= 0))
        m_mass.change_dir_y();
}
