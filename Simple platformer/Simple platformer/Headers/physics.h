#ifndef PHYSICS_H
#define PHYSICS_H


/*/////////////////////////////////
// External library dependencies //
/////////////////////////////////*/

//SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/*/////////////////////////////////
// Internal header dependencies  //
/////////////////////////////////*/

#include "animation.h"
#include "terrain.h"

/*/////////////////////////////////
//           Functions           //
/////////////////////////////////*/

void gravity(sf::Sprite& target){
  target.move(0, 0.1);
}

bool collision(sf::Sprite& target, Terrain& level){

  sf::FloatRect targetBox = target.getGlobalBounds();
  sf::FloatRect levelBox = level.getBounds();

  if (targetBox.intersects(levelBox)){
    return true;
  }
  else {
    return false;
  }

}

#endif
