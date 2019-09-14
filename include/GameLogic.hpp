//
// Created by dan9c on 9/11/2019.
//

#ifndef CSCI437_GAMELOGIC_HPP
#define CSCI437_GAMELOGIC_HPP

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "PaddleDirection.hpp"

// Forward declarations
namespace sf { class Time; }

class GameLogic
{
public:
    // Constructors
    GameLogic() = default;

    // Game loop functionality
    void init(const sf::Vector2u& dimensions);
    void update(sf::Time& delta);

    // State accessors for paddle
    sf::Vector2f getPaddlePosition(int paddle) const;
    sf::Vector2f getPaddleSize(int paddle) const;

    // State accessors for ball
    sf::Vector2f getBallPosition() const;

    // Commands
    void movePaddle(int paddle, PaddleDirection direction);

private:
    sf::Vector2u gameDimensions;

    sf::FloatRect leftPaddle;
    sf::FloatRect rightPaddle;

    float leftVelocity;
    float rightVelocity;
};


#endif //CSCI437_GAMELOGIC_HPP
