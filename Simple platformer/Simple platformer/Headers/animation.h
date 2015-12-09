#ifndef ANIMATION_H
#define ANIMATION_H


/*/////////////////////////////////
// External library dependencies //
/////////////////////////////////*/

//C standard
#include <string>

//SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/*/////////////////////////////////
//           Functions           //
/////////////////////////////////*/

void idle(sf::Sprite& target){
  target.setTextureRect(sf::IntRect(0, 0, 10, 30));
}

void movement(sf::Sprite& target, std::string direction){
  if (direction == "right"){
    target.setTextureRect(sf::IntRect(10, 0, 10, 30));
  }
  else if (direction == "left"){
    target.setTextureRect(sf::IntRect(20, 0, 10, 30));
  }
  else if (direction == "up"){
    target.setTextureRect(sf::IntRect(30, 0, 10, 30));
  }
  else if (direction == "down"){
    target.setTextureRect(sf::IntRect(40, 0, 10, 30));
  }

}

#endif
