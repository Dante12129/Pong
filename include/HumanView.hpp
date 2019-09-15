//
// Created by dan9c on 9/13/2019.
//

#ifndef CSCI437_HUMANVIEW_HPP
#define CSCI437_HUMANVIEW_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include "PaddleDirection.hpp"

// Forward declarations
namespace sf { class RenderWindow; }
class GameLogic;

class HumanView
{
public:
    // Constructors
    HumanView() = default;

    // Game loop functionality
    void init(const GameLogic& logic);
    void getKeyboardInput();
    void sendCommandsTo(GameLogic& logic) const;
    void updateFrom(const GameLogic& logic);
    void draw(sf::RenderWindow& window);

private:
    PaddleDirection directionToMove;

    sf::RectangleShape leftPaddle;
    sf::RectangleShape rightPaddle;
    sf::CircleShape ball;
};


#endif //CSCI437_HUMANVIEW_HPP
