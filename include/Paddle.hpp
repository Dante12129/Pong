//
// Created by dan9c on 9/15/2019.
//

#ifndef CSCI437_PADDLE_HPP
#define CSCI437_PADDLE_HPP

#include <SFML/Graphics/Rect.hpp>

// Forward declarations
namespace sf { class Time; }

class Paddle
{
public:
    // Lifetime methods
    void init(const sf::Vector2f& position, const sf::Vector2f& size);

    // Commands
    void move(const sf::Time& delta);

    // State accessors
    sf::Vector2f getPosition() const;
    sf::Vector2f getSize() const;

    // State setters
    void setPosition(const sf::Vector2f& position);
    void setSize(const sf::Vector2f& size);
    void setVelocity(float vel);

private:
    sf::FloatRect representation;
    float velocity;
};


#endif //CSCI437_PADDLE_HPP
