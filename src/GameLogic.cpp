//
// Created by dan9c on 9/11/2019.
//

#include "GameLogic.hpp"

#include <SFML/System/Time.hpp>

void GameLogic::init()
{
}

void GameLogic::update(sf::Time& delta)
{
}

sf::Vector2f GameLogic::getPaddlePosition(int paddle) const
{
  if(paddle == 0) return {0, 0};
  else if (paddle == 1) return {300, 0};
  else return {-100, -100};
}

sf::Vector2f GameLogic::getPaddleSize(int paddle) const
{
  return sf::Vector2f(25, 100);
}

sf::Vector2f GameLogic::getBallPosition() const
{
  return sf::Vector2f();
}
