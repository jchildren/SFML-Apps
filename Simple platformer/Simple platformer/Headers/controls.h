//controls.h

//defines movement of sprites based on inputs from hardware

#ifndef CONTROLS_H
#define CONTROLS_H


/*/////////////////////////////////
// External library dependencies //
/////////////////////////////////*/

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/*/////////////////////////////////
// Internal header dependencies  //
/////////////////////////////////*/

#include "animation.h"

/*/////////////////////////////////
//           Functions           //
/////////////////////////////////*/

void moveKeyboard(sf::Sprite& target){
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
    // left key is pressed: move our character
    target.move(0.3f, 0);
    movement(target, "right");
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
    // left key is pressed: move our character
    target.move(-0.3f, 0);
    movement(target, "left");
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    // left key is pressed: move our character
    target.move(0, -0.3f);
    movement(target, "up");
  }
  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    // left key is pressed: move our character
    target.move(0, 0.3f);
    movement(target, "down");
  }
}



#endif
