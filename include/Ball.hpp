//
// Created by dan9c on 9/15/2019.
//

#ifndef CSCI437_BALL_HPP
#define CSCI437_BALL_HPP

#include <SFML/System/Vector2.hpp>

class Ball
{
public:
    // Lifetime methods
    void init();

    // State accessors
    sf::Vector2f getCenter() const;
    float getRadius() const;

private:
    sf::Vector2f center;
    float radius;
};


#endif //CSCI437_BALL_HPP
