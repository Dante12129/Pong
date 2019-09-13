//
// Created by dan9c on 9/13/2019.
//

#include "HumanView.hpp"

#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

void HumanView::init()
{
  directionToMove = PaddleDirection::None;
}

void HumanView::getKeyboardInput()
{
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) directionToMove = PaddleDirection::Down;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) directionToMove = PaddleDirection::Up;
  else directionToMove = PaddleDirection::None;
}

void HumanView::draw(sf::RenderWindow& window)
{
}
