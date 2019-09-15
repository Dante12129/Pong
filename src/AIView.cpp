//
// Created by dan9c on 9/15/2019.
//

#include "AIView.hpp"

#include "GameLogic.hpp"

void AIView::init(const GameLogic& logic)
{
  directionToMove = PaddleDirection::None;
}

void AIView::sendCommandsTo(GameLogic& logic) const
{
  logic.movePaddle(1, directionToMove);
}

void AIView::updateFrom(const GameLogic& logic)
{
  sf::Vector2f ballPosition = logic.getBallPosition();
  sf::Vector2f paddlePosition = logic.getPaddlePosition(1);

  if(ballPosition.y < paddlePosition.y)
    directionToMove = PaddleDirection::Up;
  else if(ballPosition.y > paddlePosition.y)
    directionToMove = PaddleDirection::Down;
  else
    directionToMove = PaddleDirection::None;
}
