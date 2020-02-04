#pragma once
#include "Sprite.h"
#include "Animal.h"
#include "Console.h"


#define MAXANIMALS 15
class Playground
{
private:
	// Object containers
	int noOfAnimals = 0;
	// array of references are illegal
	Sprite *animals[MAXANIMALS];
	// Technical object grouping console operations
	Console &console;

public:
	// Constructors
	Playground(Console &console);
	~Playground();

	void AddAnimal(Sprite &animal);
	void AnimalsDoDraw();
	void AnimalsDoAction();
	void Simulate();
};

