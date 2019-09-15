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
  leftPaddle.init({0, 0}, paddleSize);
  rightPaddle.init({gameDimensions.x - paddleSize.x, 0}, paddleSize);

  // Setup ball
  ball.init();
}

void GameLogic::update(sf::Time& delta)
{
  // Move paddles appropriate amount
  leftPaddle.move(delta);
  rightPaddle.move(delta);

  // Move ball
  ball.move(delta);

  // Ensure paddles don't leave the playing area
  if(leftPaddle.getPosition().y < 0) leftPaddle.setPosition({leftPaddle.getPosition().x, 0});
  else if(leftPaddle.getPosition().y + leftPaddle.getSize().y > gameDimensions.y) leftPaddle.setPosition({leftPaddle.getPosition().x, gameDimensions.y - leftPaddle.getSize().y});

  if(rightPaddle.getPosition().y < 0) rightPaddle.setPosition({rightPaddle.getPosition().x, 0});
  else if(rightPaddle.getPosition().y + rightPaddle.getSize().y > gameDimensions.y) rightPaddle.setPosition({rightPaddle.getPosition().x, gameDimensions.y - rightPaddle.getSize().y});
}

sf::Vector2f GameLogic::getPaddlePosition(int paddle) const
{
  if(paddle == 0) return leftPaddle.getPosition();
  else if(paddle == 1) return rightPaddle.getPosition();
  else return {-100, -100};
}

sf::Vector2f GameLogic::getPaddleSize(int paddle) const
{
  if(paddle == 0) return leftPaddle.getSize();
  else if(paddle == 1) return rightPaddle.getSize();
  else return {0, 0};
}

sf::Vector2f GameLogic::getBallPosition() const
{
  return ball.getCenter();
}

float GameLogic::getBallRadius() const
{
  return ball.getRadius();
}

void GameLogic::movePaddle(int paddle, PaddleDirection direction)
{
  // Select appropriate paddle
  Paddle& selectedPaddle = leftPaddle;
  if(paddle == 1) selectedPaddle = rightPaddle;

  // Apply movement to paddle
  if(direction == PaddleDirection::Up) selectedPaddle.setVelocity(-200);
  else if(direction == PaddleDirection::Down) selectedPaddle.setVelocity(200);
  else selectedPaddle.setVelocity(0);
}
