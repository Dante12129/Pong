//
// Created by dan9c on 9/13/2019.
//

#ifndef CSCI437_HUMANVIEW_HPP
#define CSCI437_HUMANVIEW_HPP

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Text.hpp>

#include "PaddleDirection.hpp"

// Forward declarations
namespace sf { class RenderWindow; class Event; }
class GameLogic;

class HumanView
{
public:
    // Constructors
    HumanView() = default;

    // Game loop functionality
    void init(const GameLogic& logic, const sf::Vector2u& dimensions);
    void getKeyboardInput();
    void processEvents(const sf::Event& event);
    void sendCommandsTo(GameLogic& logic, bool& running, float& timeMultiplier) const;
    void updateFrom(const GameLogic& logic);
    void draw(sf::RenderWindow& window);

private:
    // Elements to keep track of
    sf::Vector2u viewDimensions;
    PaddleDirection directionToMove;
    mutable bool restartRequested = false;
    bool quitRequested = false;
    bool paused = false;

    // Game object visuals
    sf::RectangleShape leftPaddle;
    sf::RectangleShape rightPaddle;
    sf::CircleShape ball;

    // Game value visuals
    sf::Font mainFont;
    sf::Text playerScore;
    sf::Text aiScore;
    sf::Text finalMessage;
    sf::Text restartInstruction;
};


#endif //CSCI437_HUMANVIEW_HPP
