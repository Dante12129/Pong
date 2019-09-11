//
// Created by dan9c on 9/11/2019.
//

#ifndef CSCI437_GAMELOGIC_HPP
#define CSCI437_GAMELOGIC_HPP

// Forward declarations
namespace sf { class Time; }

class GameLogic
{
public:
    // Constructors

    // Game Loop Functionality
    void init();
    void update(sf::Time& delta);
};


#endif //CSCI437_GAMELOGIC_HPP
