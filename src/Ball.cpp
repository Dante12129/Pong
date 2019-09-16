//
// Created by dan9c on 9/15/2019.
//

#include "Ball.hpp"

#define _USE_MATH_DEFINES
#include <cmath>

#include <SFML/System/Time.hpp>

namespace
{
  float degreesToRadians(float deg)
  {
    return deg * M_PI / 180;
  }
}

void Ball::init(const sf::Vector2f& center, float vel, float ang)
{
  this->center = center;
  radius = 20;
  velocity = vel;
  angle = ang;
}

void Ball::move(const sf::Time& delta)
{
  // Calculate velocity vector
  sf::Vector2f calculatedVelocity(velocity * std::cos(degreesToRadians(angle)), velocity * std::sin(degreesToRadians(angle)));

  // Actual move
  center.x += calculatedVelocity.x * delta.asSeconds();
  center.y += calculatedVelocity.y * delta.asSeconds();
}

sf::Vector2f Ball::getCenter() const
{
  return center;
}

float Ball::getRadius() const
{
  return radius;
}

float Ball::getVelocity() const
{
  return velocity;
}

float Ball::getAngle() const
{
  return angle;
}

void Ball::setCenter(const sf::Vector2f& center)
{
  this->center = center;
}

void Ball::setVelocity(float vel)
{
  velocity = vel;
}

void Ball::setAngle(float ang)
{
  angle = ang;
}
