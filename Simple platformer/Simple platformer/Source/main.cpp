//main.cpp

/*
// This is the c++ file containing the main function which is the primary
// function executed by the program when run
//
// All other subroutines and objects are initialised and called from this file
//
*/


/*/////////////////////////////////
// External library dependencies //
/////////////////////////////////*/

//c standard
#include <string>
#include <iostream>

//SFML
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

/*/////////////////////////////////
// Internal header dependencies  //
/////////////////////////////////*/

#include "controls.h"
#include "events.h"
#include "physics.h"
#include "terrain.h"

// Here follows some const variables for window sizing
// these will hopefully be replaced later with a settings file
// hence they follow the non-const naming convention
const unsigned int screenWidth = 640;
const unsigned int screenHeight = 480;


/*/////////////////////////////////
//         Main function         //
/////////////////////////////////*/

int main (){

  // initialises "window" as an object of the sf::RenderWindow type
  // this is the final target for all drawn objects
  sf::RenderWindow window(sf::VideoMode(screenWidth, screenHeight), "the game");

  //
  sf::Clock globalClock;

  // defines the foreground render texture that will be rendered to by every
  // other texture off-screen except the background, this allows the level to be
  // loaded to memory at the start with a view controlling the camera
  sf::RenderTexture foreground;
  foreground.create(640, 480);

  // initialises a view centered on the player object
  // centered currently on the player
  // needs to be made more "dynamic" later
  const sf::Vector2f VIEW_CENTER(320.f, 240.f);
  const sf::Vector2f VIEW_SIZE(128.f, 96.f);

  sf::View playerView(VIEW_CENTER, VIEW_SIZE);


  // initialises the background texture object
  sf::Texture background;

  // loads the background image from a file relative to executable path
  if(!background.loadFromFile("background.png", sf::IntRect(0, 0, 640, 480))){
    //error
	sf::err();
    return 1;
  };

  sf::Sprite backgroundSprite(background);


  // initialises the player character sprite object
  // this sprite will load an image with sections
  sf::Texture playerTexture;

  // loads the player texture image from a file relative to executable path
  if(!playerTexture.loadFromFile("player.png")){
    //error
	sf::err();
    return 1;
  };
  sf::Sprite playerSprite(playerTexture, sf::IntRect(0, 0, 16, 32));

  const int level[] = {
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0,
    0, 1, 2, 0, 2, 1, 1, 0, 0, 1, 1, 3, 0, 1, 1, 6, 0, 1, 1, 0, 0, 1, 1, 0,

  };

  Terrain map;
  if (!map.load("terrain.png", sf::Vector2u(16, 16), level,
	  40, 20))
  {
	  sf::err();
  };


  // run the program as long as the window is open
  while (window.isOpen()){

    handleEvents(window);
    moveKeyboard(playerSprite);
    if(!collision(playerSprite, map)){
      gravity(playerSprite);
    }
    playerView.setCenter(playerSprite.getPosition());

    //foreground drawing
    foreground.clear(sf::Color::Transparent);
    foreground.setView(playerView);
    foreground.draw(map);
    foreground.draw(playerSprite);
    foreground.display();
    sf::Sprite foregroundSprite(foreground.getTexture());

    //final drawing
    window.clear(sf::Color::Black);
    window.draw(backgroundSprite);
    window.draw(foregroundSprite);
    // End the current frame and display its contents on screen
    window.display();

  }

  return 0;
}
