#include "Textured.h"


Textured::Textured()
{
}


Textured::~Textured()
{
	delete sprite_;
}

int Textured::set_sprite(const char* file, sf::Vector2f position){
	if (!texture_){
		texture_ = new sf::Texture();
	}

	if (!texture_->loadFromFile(file)){
		//error
	}

	sprite_ = new sf::Sprite();
	sprite_->setTexture(*texture_);
	sprite_->setPosition(position);

	return 0;
}