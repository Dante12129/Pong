#include <SFML/Graphics.hpp>

#include "AIView.hpp"
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
  humanView.init(logic,  app.getSize());
  AIView ai;
  ai.init(logic);

  // setup timekeeping
  sf::Clock timekeeper;
  sf::Time delta;
  float timeMultiplier = 1.0;

  // start main loop
  bool running = true;
  while(running)
  {
    // keep track of frame
    delta = timekeeper.restart();

    // process events
    sf::Event event;
    while(app.pollEvent(event))
    {
      // Exit
      if(event.type == sf::Event::Closed)
      {
        running = false;
        app.close();
      }
      // Let view handle events relevant to itself
      humanView.processEvents(event);
    }
    humanView.getKeyboardInput();

    // process logic
    humanView.sendCommandsTo(logic, running, timeMultiplier);
    ai.sendCommandsTo(logic);
    logic.update(delta *= timeMultiplier);
    humanView.updateFrom(logic);
    ai.updateFrom(logic);

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
