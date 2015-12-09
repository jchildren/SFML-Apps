#pragma once
#include "Physical.h"
#include "Textured.h"

class Projectile :
	public Physical,
	public Textured
{
public:
	Projectile();
	virtual ~Projectile();
};

