//
// Created by dan9c on 9/11/2019.
//

#include "GameLogic.hpp"

#include <SFML/System/Time.hpp>

void GameLogic::init(const sf::Vector2u& area)
{
  // Set up the playing area
  gameArea = area;

  // Put paddles in starting positions
  const sf::Vector2f paddleSize(25, 100);
  leftPaddle = sf::FloatRect({0, 0}, paddleSize);
  rightPaddle = sf::FloatRect({gameArea.x - paddleSize.x, 0}, paddleSize);
}

void GameLogic::update(sf::Time& delta)
{
  // Move paddles appropriate amount
  leftPaddle.top += leftVelocity * delta.asSeconds();
  rightPaddle.top += rightVelocity * delta.asSeconds();
}

sf::Vector2f GameLogic::getPaddlePosition(int paddle) const
{
  if(paddle == 0) return {leftPaddle.left, leftPaddle.top};
  else if(paddle == 1) return {rightPaddle.left, rightPaddle.top};
  else return {-100, -100};
}

sf::Vector2f GameLogic::getPaddleSize(int paddle) const
{
  if(paddle == 0) return {leftPaddle.width, leftPaddle.height};
  else if(paddle == 1) return {rightPaddle.width, rightPaddle.height};
  else return {0, 0};
}

sf::Vector2f GameLogic::getBallPosition() const
{
  return sf::Vector2f();
}

void GameLogic::movePaddle(int paddle, PaddleDirection direction)
{
  // Select appropriate velocity
  float& velocity = leftVelocity;
  if(paddle == 1) velocity = rightVelocity;

  // Apply movement to paddle
  if(direction == PaddleDirection::Up)
  {
    velocity = -100;
  }
  else if(direction == PaddleDirection::Down)
  {
    velocity = 100;
  }
}
