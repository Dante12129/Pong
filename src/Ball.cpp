//
// Created by dan9c on 9/15/2019.
//

#include "Ball.hpp"

void Ball::init()
{
  center = {200, 200};
  radius = 20;
}

sf::Vector2f Ball::getCenter() const
{
  return center;
}

float Ball::getRadius() const
{
  return radius;
}
