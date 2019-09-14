#include <SFML/Graphics.hpp>

#include "GameLogic.hpp"
#include "HumanView.hpp"

int main(int argc, char** argv)
{
  // create main window
  sf::RenderWindow app(sf::VideoMode(800,600,32), "Pong", sf::Style::Titlebar | sf::Style::Close);

  // setup logic
  GameLogic logic;
  logic.init(app.getSize());

  // setup views
  HumanView humanView;
  humanView.init(logic);

  // setup timekeeping
  sf::Clock timekeeper;
  sf::Time delta;

  // start main loop
  while(app.isOpen())
  {
    // keep track of frame
    delta = timekeeper.restart();

    // process events
    sf::Event Event;
    while(app.pollEvent(Event))
    {
      // Exit
      if(Event.type == sf::Event::Closed)
        app.close();
    }
    humanView.getKeyboardInput();

    // process logic
    logic.update(delta);

    // clear screen and fill with black
    app.clear(sf::Color::Black);

    // draw human view
    humanView.draw(app);

    // display
    app.display();
  }

  // Done.
  return 0;
}
