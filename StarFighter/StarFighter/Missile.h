#pragma once
#include "Projectile.h"

class Missile :
	public Projectile
{
public:
	Missile(sf::Vector2f position, sf::Vector2f velocity);
	virtual ~Missile();

};

