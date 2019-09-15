//
// Created by dan9c on 9/15/2019.
//

#include "Ball.hpp"

#include <SFML/System/Time.hpp>

void Ball::init()
{
  center = {200, 200};
  radius = 20;
  velocity = {-300, 300};
}

void Ball::move(const sf::Time& delta)
{
  center.x += velocity.x * delta.asSeconds();
  center.y += velocity.y * delta.asSeconds();
}

sf::Vector2f Ball::getCenter() const
{
  return center;
}

float Ball::getRadius() const
{
  return radius;
}

sf::Vector2f Ball::getVelocity() const
{
  return velocity;
}

void Ball::setVelocity(const sf::Vector2f& vel)
{
  velocity = vel;
}
