//
// Created by dan9c on 9/11/2019.
//

#ifndef CSCI437_GAMELOGIC_HPP
#define CSCI437_GAMELOGIC_HPP

#include <SFML/System/Vector2.hpp>

// Forward declarations
namespace sf { class Time; }

class GameLogic
{
public:
    // Constructors
    GameLogic() = default;

    // Game loop functionality
    void init();
    void update(sf::Time& delta);

    // State accessors for paddle
    sf::Vector2f getPaddlePosition(int paddle) const;
    sf::Vector2f getPaddleSize(int paddle) const;

    // State accessors for ball
    sf::Vector2f getBallPosition() const;
};


#endif //CSCI437_GAMELOGIC_HPP
