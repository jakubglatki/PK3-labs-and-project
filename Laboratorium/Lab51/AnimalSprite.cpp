#include "stdafx.h"
#include "AnimalSprite.h"

#pragma region Constructors
AnimalSprite::AnimalSprite() : AnimalSprite("Noname animal", 0, true, 0)
{}

AnimalSprite::AnimalSprite(std::string name, int age, bool isMale, WORD color) : Animal(name, age, isMale), Sprite(color)
{
	x = static_cast <float> (5 + rand() % 70);
	y = static_cast <float> (5 + rand() % 15);
}

AnimalSprite::AnimalSprite(const AnimalSprite &animal) : Animal(animal), Sprite(animal)
{
	color = animal.color;
	x = animal.x;
	y = animal.y;

	if (animal.imageData)
	{
		imageData = new char[strlen(animal.imageData) + 1];
		memcpy(imageData, animal.imageData, strlen(animal.imageData) + 1);
	}
}

AnimalSprite::AnimalSprite(AnimalSprite &&animal) : Animal(animal), Sprite(animal)
{
	color = animal.color;
	x = animal.x;
	y = animal.y;
	animal.imageData = nullptr;
}
AnimalSprite::~AnimalSprite()
{
	if (imageData)
		delete[] imageData;
}

AnimalSprite& AnimalSprite::operator= (const AnimalSprite & animal)
{
	x = animal.x;
	y = animal.y;
	name = animal.name;
	age = animal.age;
	isMale = animal.isMale;

	if (imageData)
	{
		delete[] imageData;
		imageData = nullptr;
	}

	if (animal.imageData)
	{
		imageData = new char[strlen(animal.imageData) + 1];
		memcpy(imageData, animal.imageData, strlen(animal.imageData) + 1);
	}


	return *this;
}

AnimalSprite& AnimalSprite::operator= (AnimalSprite&& animal)
{
	x = animal.x;
	y = animal.y;
	name = animal.name;
	age = animal.age;
	isMale = animal.isMale;

	if (imageData)
		delete[] imageData;

	imageData = animal.imageData;
	animal.imageData = nullptr;


	return *this;
}


string AnimalSprite::DoGetInfo()
{
	return GetName() + " [" + actionText + "]";
}
