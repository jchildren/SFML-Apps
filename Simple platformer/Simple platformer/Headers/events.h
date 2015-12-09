//events.h

#ifndef EVENTS_H
#define EVENTS_H

/*/////////////////////////////////
// External library dependencies //
/////////////////////////////////*/

//C standard
#include <string>

//SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


/*/////////////////////////////////
// Internal header dependencies  //
/////////////////////////////////*/

//empty

/*/////////////////////////////////
//           Functions           //
/////////////////////////////////*/


void handleEvents(sf::RenderWindow& window){
  // check all the window's events that were triggered since the last iteration of the loop
  sf::Event event;
  while (window.pollEvent(event)){
    // "close requested" event: we close the window
    if (event.type == sf::Event::Closed){
      window.close();
      std::cout << "window closed" << "\n";
    }

    /*
    // catch the resize events
    if (event.type == sf::Event::Resized){
      // update the view to the new size of the window
      sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
      window.setView(sf::View(visibleArea));
    }
    */

  }
}

#endif
