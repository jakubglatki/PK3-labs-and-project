#pragma once
#include "Console.h"
#include "Animal.h"
#include "Sprite.h"

class AnimalSprite : public Animal, public Sprite
{
public:
	AnimalSprite();
	AnimalSprite(std::string, int, bool, WORD);
	AnimalSprite(const AnimalSprite &);
	AnimalSprite(AnimalSprite &&);
	virtual std::string DoGetInfo() override;
	~AnimalSprite();
	AnimalSprite& operator= (const AnimalSprite & animal);
	AnimalSprite& operator= (AnimalSprite && animal);
};