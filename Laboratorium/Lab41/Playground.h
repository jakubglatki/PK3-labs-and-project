#pragma once
#include "Animal.h"
#include "Console.h"


#define MAXANIMALS 15
class Playground
{
private:
	// Object containers
	int noOfAnimals = 0;
	// array of references are illegal
	Animal *animals[MAXANIMALS];
	// Technical object grouping console operations
	Console &console;

public:
	// Constructors
	Playground(Console &console);
	~Playground();

	void AddAnimal(Animal &animal);
	void AnimalsDoDraw();
	void AnimalsDoAction();
	void Chase(int bee, int dog);
	bool Stinging(int dog, int bee);
	bool Detection();
	int BeeSeen();


	void Simulate();
};

