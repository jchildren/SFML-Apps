#pragma once

#include "Physics.h"

class Physical
{
public:
	Physical();
	virtual ~Physical();

private:
	sf::Vector2f position_;
	sf::Vector2f velocity_;

public:

	sf::Vector2f position(){ return position_; };
	sf::Vector2f velocity(){ return velocity_; };

	void set_position(sf::Vector2f position){ position_ = position; }
	void set_velocity(sf::Vector2f velocity){ velocity_ = velocity; }

};
