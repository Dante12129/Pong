//
// Created by dan9c on 9/15/2019.
//

#ifndef CSCI437_AIVIEW_HPP
#define CSCI437_AIVIEW_HPP

#include "PaddleDirection.hpp"

// Forward declarations
class GameLogic;

class AIView
{
public:
    // Game loop functionality
    void init(const GameLogic& logic);
    void sendCommandsTo(GameLogic& logic) const;
    void updateFrom(const GameLogic& logic);

private:
    PaddleDirection directionToMove;
};


#endif //CSCI437_AIVIEW_HPP
