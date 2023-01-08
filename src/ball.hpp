#ifndef BALL_HPP
#define BALL_HPP
#include <SFML/Graphics/CircleShape.hpp>
#include "physics.hpp"

class ball : public sf::CircleShape
{
    physics m_mass;
    unsigned int m_plr1_score,
                m_plr2_score;
public:
    ball();
    ~ball() = default;

    void restart();
    void update(float dt);
    inline void apply_force(const sf::Vector2f& force)
    { m_mass.apply_force(force); }
    inline unsigned int get_player1_score()
    { return m_plr1_score; }
    inline unsigned int get_player2_score()
    { return m_plr2_score; }
private:
    void collision_border();
};

#endif // BALL_HPP
