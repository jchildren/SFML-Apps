#pragma once
#include <SFML/Graphics.hpp>
#include "Missile.h"

class Fighter:
	public Physical,
	public Textured
{
public:
	Fighter(sf::Vector2f position_vector);
	virtual ~Fighter();

public:
	sf::Sprite* sprite(){ return sprite_; };
	Missile* shoot();

};

