//
// Created by dan9c on 9/13/2019.
//

#include "HumanView.hpp"

#include <stdexcept>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
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

  // Setup restart message
  restartInstruction.setFont(mainFont);
  restartInstruction.setString("Press space to reset\nPress q to quit");
  restartInstruction.setCharacterSize(60);
  restartInstruction.setOrigin({restartInstruction.getLocalBounds().left + restartInstruction.getLocalBounds().width / 2.f, 0});
}

void HumanView::getKeyboardInput()
{
  // Paddle controls
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)) directionToMove = PaddleDirection::Down;
  else if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)) directionToMove = PaddleDirection::Up;
  else directionToMove = PaddleDirection::None;

  // Restart control
  restartRequested = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

  // Quit control
  quitRequested = sf::Keyboard::isKeyPressed(sf::Keyboard::Q);
}

void HumanView::processEvents(const sf::Event& event)
{
  if(event.type == sf::Event::LostFocus)
    paused = true;
  else if(event.type == sf::Event::GainedFocus)
    paused = false;
}

void HumanView::sendCommandsTo(GameLogic& logic, bool& running, float& timeMultiplier) const
{
  // Tell paddle to move
  logic.movePaddle(0, directionToMove);

  // Restart if needed
  if(restartRequested && logic.checkWin())
  {
    restartRequested = false;
    logic.restart();
  }

  // Quit if need
  if(quitRequested && logic.checkWin())
  {
    running = false;
  }

  // Pause if needed
  timeMultiplier = paused ? 0.0 : 1.0;
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
    // Show win/lose messages
    finalMessage.setString(logic.getWinningPlayer() == 0 ? "You won!" : "You lost!");
    finalMessage.setOrigin({finalMessage.getLocalBounds().left + finalMessage.getLocalBounds().width / 2.f, 0});
    finalMessage.setPosition({viewDimensions.x / 2.f, 100});
    restartInstruction.setPosition({viewDimensions.x / 2.f, 200});
    restartInstruction.setFillColor(sf::Color::White);

    // Hide Ball
    ball.setFillColor(sf::Color::Transparent);
  }
  else
  {
    // Hide win/lose messages
    finalMessage.setString("");
    restartInstruction.setFillColor(sf::Color::Transparent);

    // Show ball
    ball.setFillColor(sf::Color::Cyan);
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
  window.draw(restartInstruction);
}
