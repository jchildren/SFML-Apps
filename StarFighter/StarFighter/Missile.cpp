#include "Missile.h"


Missile::Missile(sf::Vector2f position, sf::Vector2f velocity)
{

	set_sprite("missile.png", position);

	set_position(position);
	set_velocity(velocity);
}


Missile::~Missile()
{
	delete sprite_;
}
