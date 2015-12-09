#include "Fighter.h"


Fighter::Fighter(sf::Vector2f position)
{
	set_sprite("starfighter.png", position);

	set_position(position);
	set_velocity(sf::Vector2f(0, 0));
}


Fighter::~Fighter()
{
}

Missile* Fighter::shoot()
{
	Missile* missile = new Missile(position(), sf::Vector2f(0, -100));

	return &*missile;
}
