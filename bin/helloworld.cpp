#include <SFML/Graphics.hpp>

#include "GameLogic.hpp"

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow App(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar | sf::Style::Close);

  // setup logic
  GameLogic logic;
  logic.init();

  // setup timekeeping
  sf::Clock timekeeper;
  sf::Time delta;

  // start main loop
  while(App.isOpen())
  {
    // keep track of frame
    delta = timekeeper.restart();

    // process events
    sf::Event Event;
    while(App.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        App.close();
    }

    // process logic
    logic.update(delta);

    // clear screen and fill with blue
    App.clear(sf::Color::Black);

    // display
    App.display();
  }

  // Done.
  return 0;
}
