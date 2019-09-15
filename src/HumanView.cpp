//
// Created by dan9c on 9/13/2019.
//

#include "HumanView.hpp"

#include <stdexcept>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>

#include "GameLogic.hpp"

void HumanView::init(const GameLogic& logic, const sf::Vector2u& dimensions)
{
  // Save dimensions
  viewDimensions = dimensions;

  // Make sure player paddle is initially stationary
  directionToMove = PaddleDirection::None;

  // Set paddles to initial sizes and positions as defined by logic
  leftPaddle.setSize(logic.getPaddleSize(0));
  leftPaddle.setPosition(logic.getPaddlePosition(0));
  rightPaddle.setSize(logic.getPaddleSize(1));
  rightPaddle.setPosition(logic.getPaddlePosition(1));

  // Set ball to initial position and size, making sure its origin is on the center
  float radius = logic.getBallRadius();
  ball.setRadius(radius);
  ball.setOrigin({radius, radius});
  ball.setPosition(logic.getBallPosition());

  // Set colors
  leftPaddle.setFillColor(sf::Color::Green);
  rightPaddle.setFillColor(sf::Color::Red);
  ball.setFillColor(sf::Color::Cyan);

  // Load font and use it for scores
  if(!mainFont.loadFromFile("ShareTechMono-Regular.ttf"))
  {
    throw std::runtime_error("Could not load font");
  }
  playerScore.setFont(mainFont);
  aiScore.setFont(mainFont);
  finalMessage.setFont(mainFont);

  // Position and size scores
  playerScore.setPosition({viewDimensions.x / 4.f, 0});
  playerScore.setCharacterSize(48);
  aiScore.setPosition({3.f * viewDimensions.x / 4.f, 0});
  aiScore.setCharacterSize(48);

  // Set size of win/lose message
  finalMessage.setCharacterSize(72);
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
  // Update paddle sizes and position
  leftPaddle.setSize(logic.getPaddleSize(0));
  leftPaddle.setPosition(logic.getPaddlePosition(0));
  rightPaddle.setSize(logic.getPaddleSize(1));
  rightPaddle.setPosition(logic.getPaddlePosition(1));

  // Update ball position
  ball.setPosition(logic.getBallPosition());

  // Update scores
  playerScore.setString(std::to_string(logic.getScore(0)));
  aiScore.setString(std::to_string(logic.getScore(1)));

  // Check for win
  if(logic.checkWin())
  {
    finalMessage.setString("Someone won!");
    finalMessage.setOrigin({finalMessage.getLocalBounds().left + finalMessage.getLocalBounds().width / 2.f, 0});
    finalMessage.setPosition({viewDimensions.x / 2.f, 100});
  }
}

void HumanView::draw(sf::RenderWindow& window)
{
  window.draw(leftPaddle);
  window.draw(rightPaddle);
  window.draw(playerScore);
  window.draw(aiScore);
  window.draw(ball);
  window.draw(finalMessage);
}
