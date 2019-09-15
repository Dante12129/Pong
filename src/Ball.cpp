//
// Created by dan9c on 9/15/2019.
//

#include "Ball.hpp"

#include <SFML/System/Time.hpp>

void Ball::init(const sf::Vector2f& vel)
{
  center = {100, 100};
  radius = 20;
  velocity = vel;
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

void Ball::setCenter(const sf::Vector2f& center)
{
  this->center = center;
}

void Ball::setVelocity(const sf::Vector2f& vel)
{
  velocity = vel;
}
