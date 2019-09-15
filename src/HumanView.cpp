//
// Created by dan9c on 9/13/2019.
//

#include "HumanView.hpp"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "GameLogic.hpp"

void HumanView::init(const GameLogic& logic)
{
  // Make sure player paddle is initially stationary
  directionToMove = PaddleDirection::None;

  // Set paddles to initial sizes and positions as defined by logic
  leftPaddle.setSize(logic.getPaddleSize(0));
  leftPaddle.setPosition(logic.getPaddlePosition(0));
  rightPaddle.setSize(logic.getPaddleSize(1));
  rightPaddle.setPosition(logic.getPaddlePosition(1));

  // Set ball to inital position and size, making sure its origin is on the center
  float radius = logic.getBallRadius();
  ball.setRadius(radius);
  ball.setOrigin({radius / 2, radius / 2});
  ball.setPosition(logic.getBallPosition());
}

void HumanView::getKeyboardInput()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) directionToMove = PaddleDirection::Down;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) directionToMove = PaddleDirection::Up;
  else directionToMove = PaddleDirection::None;
}

void HumanView::sendCommandsTo(GameLogic& logic) const
{
  logic.movePaddle(0, directionToMove);
}

void HumanView::updateFrom(const GameLogic& logic)
{
  // Update paddle sizes and positon
  leftPaddle.setSize(logic.getPaddleSize(0));
  leftPaddle.setPosition(logic.getPaddlePosition(0));
  rightPaddle.setSize(logic.getPaddleSize(1));
  rightPaddle.setPosition(logic.getPaddlePosition(1));
}

void HumanView::draw(sf::RenderWindow& window)
{
  window.draw(leftPaddle);
  window.draw(rightPaddle);
  window.draw(ball);
}
