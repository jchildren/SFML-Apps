#include "Physics.h"

namespace Physics {
	template <class T>
	int update(sf::Time* time, T* object)
	{
		object->set_position(object->position() + object->velocity() * time->asSeconds());
		object->sprite()->setPosition(object->position());
		return 0;
	}

	template <class T>
	int accelerate(sf::Time* time, T* object, const char* direction){
		
		sf::Vector2f acceleration;
		

		switch (direction){
		case "left":
			acceleration = sf::Vector2f(-500, 0);
		case "right":
			acceleration = sf::Vector2f(500, 0);
		case "up":
			acceleration = sf::Vector2f(0, -500);
		case "down":
			acceleration = sf::Vector2f(0, 500);

		case default:
			return -1;
		}

		object->set_velocity(object->velocity() + acceleration * time->asSeconds());
		object->sprite()->setPosition(object->position());

		return 0;
	}
}