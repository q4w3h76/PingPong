#ifndef BALL_HPP
#define BALL_HPP
#include <SFML/Graphics/CircleShape.hpp>
#include "physics.hpp"

class ball : public sf::CircleShape
{
    physics m_mass;
public:
    ball();
    ~ball() = default;

    void restart();
    void update(float dt);
    inline void apply_force(const sf::Vector2f& force)
    { m_mass.apply_force(force); }
private:
    void collision_border();
};

#endif // BALL_HPP
