//
// Created by dan9c on 9/11/2019.
//

#ifndef CSCI437_GAMELOGIC_HPP
#define CSCI437_GAMELOGIC_HPP

#include <random>

#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "Ball.hpp"
#include "Paddle.hpp"
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

    // Commands
    void movePaddle(int paddle, PaddleDirection direction);
    void restart();

    // Handle resizing
    void onResize(sf::Vector2u newDimensions);

    // State accessors for paddle
    sf::Vector2f getPaddlePosition(int paddle) const;
    sf::Vector2f getPaddleSize(int paddle) const;

    // State accessors for ball
    sf::Vector2f getBallPosition() const;
    float getBallRadius() const;

    // State accessor for score
    int getScore(int paddle) const;

    // Sate accessors for game stage
    bool checkWin() const;
    int getWinningPlayer() const;

private:
    // RNG
    std::mt19937 rng;
    std::uniform_int_distribution<int> distribution;

    // Misc elements
    sf::Vector2u gameDimensions;
    const sf::Vector2f initialBallVelocity = {250, 250};
    const sf::Vector2f initialPaddleSize = {25, 100};
    float paddleVelocityMultiplier = 1.0;

    // Physical elements
    Paddle leftPaddle;
    Paddle rightPaddle;
    Ball ball;

    // Logical elements
    int leftScore;
    int rightScore;
};


#endif //CSCI437_GAMELOGIC_HPP
