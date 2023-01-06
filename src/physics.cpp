#include "physics.hpp"

physics::physics(const float mass, bool limit_vel, const float max_velocity)
 :  m_mass(mass), m_limit_vel(limit_vel), m_max_velocity(max_velocity) {}

const sf::Vector2f& physics::simulate(float dt)
{
    dt *= 100;
    m_velocity += sf::Vector2f((m_force.x/m_mass)*dt, (m_force.y/m_mass)*dt);
    init();
 
    if(m_limit_vel)
        if(m_velocity.x > m_max_velocity)
            m_velocity = sf::Vector2f(m_max_velocity, m_velocity.y);
        if(m_velocity.x < -m_max_velocity)
            m_velocity = sf::Vector2f(-m_max_velocity, m_velocity.y);
        if(m_velocity.y > m_max_velocity)
            m_velocity = sf::Vector2f(m_velocity.x, m_max_velocity);
        if(m_velocity.y < -m_max_velocity)
            m_velocity = sf::Vector2f(m_velocity.x, -m_max_velocity);

    return m_velocity;
}
