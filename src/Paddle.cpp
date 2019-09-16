//
// Created by dan9c on 9/15/2019.
//

#include "Paddle.hpp"

#include <SFML/System/Time.hpp>

void Paddle::init(const sf::Vector2f& position, const sf::Vector2f& size)
{
  representation = {position, size};
  velocity = 0;
}

void Paddle::move(const sf::Time& delta)
{
  representation.top += velocity * delta.asSeconds();
}

sf::Vector2f Paddle::getPosition() const
{
  return {representation.left, representation.top};
}

sf::Vector2f Paddle::getSize() const
{
  return {representation.width, representation.height};
}

void Paddle::setPosition(const sf::Vector2f& position)
{
  representation.left = position.x;
  representation.top = position.y;
}

void Paddle::setVelocity(float vel)
{
  velocity = vel;
}

void Paddle::setSize(const sf::Vector2f& size)
{
  representation.width = size.x;
  representation.height = size.y;
}
