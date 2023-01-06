#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "physics.hpp"

class player : public sf::RectangleShape
{
    physics m_mass;
    short m_direction;
    const float m_force;
    sf::Keyboard::Key m_key_up, m_key_down;
public:
    player(sf::Keyboard::Key = sf::Keyboard::Up, sf::Keyboard::Key = sf::Keyboard::Down);
    ~player() = default;

    void update(float);
    inline short get_direction()
    { return m_direction; }
private:
    void control();
    void collision_border();
};

#endif // PLAYER_HPP
