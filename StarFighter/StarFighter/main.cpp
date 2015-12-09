#include <vector>
#include <algorithm>

#include "Physics.cpp"
#include "Fighter.h"


int main()
{
	//initialisation

	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(400, 600), "StarFighter");

	sf::Clock* clock = new sf::Clock;
	sf::Time* elapsed_time = new sf::Time;

	Fighter* fighter = new Fighter(sf::Vector2f(200, 550));

	std::vector<Missile*> active_missiles;

	while (window->isOpen())
	{
		sf::Event event;
		while (window->pollEvent(event))
		{

			
			switch (event.type){
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Space){
					active_missiles.push_back(fighter->shoot());
				}
				break;
			

			case sf::Event::Closed:
				window->close();
				break;

			default:
				break;
			}

		}

		*elapsed_time = clock->getElapsedTime();

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
			Physics::accelerate(elapsed_time, fighter, "left");
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
			Physics::accelerate(elapsed_time, fighter, "right");
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
			Physics::accelerate(elapsed_time, fighter, "up");
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
			Physics::accelerate(elapsed_time, fighter, "down");
		}


		// render
		window->clear();
		window->draw(*fighter->sprite());
		Physics::update(elapsed_time, fighter);
		for (unsigned int i = 0; i<active_missiles.size(); i++) {
			window->draw(*active_missiles[i]->sprite());
			Physics::update(elapsed_time, active_missiles[i]);
		}
		window->display();
		clock->restart();

	}

	// clean up
	for (unsigned int i = 0; i < active_missiles.size(); i++) {
		delete active_missiles[i];
	}
	active_missiles.clear();

	delete fighter;
	delete elapsed_time;
	delete clock;
	delete window;

	return 0;
}