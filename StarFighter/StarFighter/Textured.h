#pragma once
#include <SFML\Graphics.hpp>

class Textured
{
public:
	Textured();
	virtual ~Textured();

public:

	sf::Texture* texture_;
	sf::Sprite* sprite_;

public:
	sf::Sprite* sprite() { return sprite_; };
	sf::Texture* texture(){ return texture_; };

	int set_sprite(const char* file, sf::Vector2f position);
};

