//
// Created by dan9c on 9/15/2019.
//

#ifndef CSCI437_BALL_HPP
#define CSCI437_BALL_HPP

#include <SFML/System/Vector2.hpp>

// Forward declarations
namespace sf { class Time; }

class Ball
{
public:
    // Lifetime methods
    void init(const sf::Vector2f& vel);

    // Commands
    void move(const sf::Time& delta);

    // State accessors
    sf::Vector2f getCenter() const;
    float getRadius() const;
    sf::Vector2f getVelocity() const;

    // State setters
    void setCenter(const sf::Vector2f& center);
    void setVelocity(const sf::Vector2f& vel);

private:
    sf::Vector2f center;
    float radius;
    sf::Vector2f velocity;
};


#endif //CSCI437_BALL_HPP
