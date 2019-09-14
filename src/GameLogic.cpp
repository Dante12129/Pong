//
// Created by dan9c on 9/11/2019.
//

#include "GameLogic.hpp"

#include <SFML/System/Time.hpp>

void GameLogic::init(const sf::Vector2u& dimensions)
{
  // Set up the playing area
  gameDimensions = dimensions;

  // Put paddles in starting positions
  const sf::Vector2f paddleSize(25, 100);
  leftPaddle = sf::FloatRect({0, 0}, paddleSize);
  rightPaddle = sf::FloatRect({gameDimensions.x - paddleSize.x, 0}, paddleSize);
}

void GameLogic::update(sf::Time& delta)
{
  // Move paddles appropriate amount
  leftPaddle.top += leftVelocity * delta.asSeconds();
  rightPaddle.top += rightVelocity * delta.asSeconds();

  // Ensure paddles don't leave the playing area
  if(leftPaddle.top < 0) leftPaddle.top = 0;
  else if(leftPaddle.top + leftPaddle.height > gameDimensions.y) leftPaddle.top = gameDimensions.y - leftPaddle.height;

  if(rightPaddle.top < 0) rightPaddle.top = 0;
  else if(rightPaddle.top + rightPaddle.height > gameDimensions.y) rightPaddle.top = gameDimensions.y - rightPaddle.height;
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
    velocity = -200;
  }
  else if(direction == PaddleDirection::Down)
  {
    velocity = 200;
  }
}
