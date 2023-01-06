#ifndef PHYSICS_HPP
#define PHYSICS_HPP

#include <SFML/System/Vector2.hpp>

class physics
{
    const float m_mass, m_max_velocity;
    const bool m_limit_vel;
    sf::Vector2f m_velocity, m_force;
public:
    // if second parametr = false, then third parametr useless
    physics(const float, bool = false, const float = 10);
    ~physics() = default;

    const sf::Vector2f& simulate(float);
    inline void apply_force(const sf::Vector2f& force)
    { m_force += force; }
    // change direction
    inline void change_dir_x()
    { m_velocity = sf::Vector2f(m_velocity.x * -1, m_velocity.y); }
    inline void change_dir_y()
    { m_velocity = sf::Vector2f(m_velocity.x, m_velocity.y * -1); }
    
    inline void init()
    { m_force = sf::Vector2f(0, 0); }
    inline void restart()
    { m_force = m_velocity = sf::Vector2f(0, 0); }
};

#endif // PHYSICS_HPP
