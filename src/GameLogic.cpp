//
// Created by dan9c on 9/11/2019.
//

#include "GameLogic.hpp"

#include <SFML/System/Time.hpp>

namespace
{
    int sign(float n)
    {
      if(n < 0) return -1;
      else if(n > 0) return 1;
      else return 0;
    }
}

void GameLogic::init(const sf::Vector2u& dimensions)
{
  // Setup the RNG
  rng.seed(0);
  distribution = std::uniform_int_distribution<>(100, 200);

  // Set up the playing area
  gameDimensions = dimensions;

  // Put paddles in starting positions
  const sf::Vector2f paddleSize(25, 100);
  leftPaddle.init({0, 0}, paddleSize);
  rightPaddle.init({gameDimensions.x - paddleSize.x, 0}, paddleSize);

  // Setup ball
  ball.init(initialBallVelocity);

  // Setup scores
  leftScore = 0;
  rightScore = 0;
}

void GameLogic::update(sf::Time& delta)
{
  // Move paddles appropriate amount
  leftPaddle.move(delta);
  rightPaddle.move(delta);

  // Move ball
  ball.move(delta);

  // Ensure paddles don't leave the playing area
  if(leftPaddle.getPosition().y < 0)
    leftPaddle.setPosition({leftPaddle.getPosition().x, 0});
  else if(leftPaddle.getPosition().y + leftPaddle.getSize().y > gameDimensions.y)
    leftPaddle.setPosition({leftPaddle.getPosition().x, gameDimensions.y - leftPaddle.getSize().y});

  if(rightPaddle.getPosition().y < 0)
    rightPaddle.setPosition({rightPaddle.getPosition().x, 0});
  else if(rightPaddle.getPosition().y + rightPaddle.getSize().y > gameDimensions.y)
    rightPaddle.setPosition({rightPaddle.getPosition().x, gameDimensions.y - rightPaddle.getSize().y});

  // Keep ball in bounds
  if(ball.getCenter().x - ball.getRadius() < 0)
  {
    ball.setCenter(static_cast<sf::Vector2f>(gameDimensions / 2u));
    rightScore += 1;
  }
  if(ball.getCenter().x + ball.getRadius() > gameDimensions.x)
  {
    ball.setCenter(static_cast<sf::Vector2f>(gameDimensions / 2u));
    leftScore += 1;
  }
  if(ball.getCenter().y - ball.getRadius() < 0 || ball.getCenter().y + ball.getRadius() > gameDimensions.y)
    ball.setVelocity({ball.getVelocity().x, -sign(ball.getVelocity().y) * (initialBallVelocity.y + distribution(rng))});

  // Check ball against paddles
  if(ball.getCenter().x - ball.getRadius() < leftPaddle.getPosition().x + leftPaddle.getSize().x &&
     ball.getCenter().y > leftPaddle.getPosition().y &&
     ball.getCenter().y < leftPaddle.getPosition().y + leftPaddle.getSize().y)
  {
    ball.setCenter({leftPaddle.getPosition().x + leftPaddle.getSize().x + ball.getRadius(), ball.getCenter().y});
    ball.setVelocity({-sign(ball.getVelocity().x) * (initialBallVelocity.x + distribution(rng)), ball.getVelocity().y});
  }

  if(ball.getCenter().x + ball.getRadius() > rightPaddle.getPosition().x &&
     ball.getCenter().y > rightPaddle.getPosition().y &&
     ball.getCenter().y < rightPaddle.getPosition().y + leftPaddle.getSize().y)
  {
    ball.setCenter({rightPaddle.getPosition().x - ball.getRadius(), ball.getCenter().y});
    ball.setVelocity({-sign(ball.getVelocity().x) * (initialBallVelocity.x + distribution(rng)), ball.getVelocity().y});
  }
}

void GameLogic::movePaddle(int paddle, PaddleDirection direction)
{
  // Select appropriate paddle
  Paddle* selectedPaddle = nullptr;
  if(paddle == 0) selectedPaddle = &leftPaddle;
  if(paddle == 1) selectedPaddle = &rightPaddle;

  // Apply movement to paddle
  if(direction == PaddleDirection::Up) selectedPaddle->setVelocity(-200);
  else if(direction == PaddleDirection::Down) selectedPaddle->setVelocity(200);
  else selectedPaddle->setVelocity(0);
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

int GameLogic::getScore(int paddle) const
{
  if(paddle == 0) return leftScore;
  else if(paddle == 1) return rightScore;
  else return -1;
}
