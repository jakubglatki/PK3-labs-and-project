#pragma once
#include "Dog.h"
#include "Dragon.h"
#include "Bee.h"
#include "Console.h"


#define MAXDOGS 15
#define MAXDRAGONS 5
#define MAXBEES 3

class Playground
{
private:
	// Array of dogs 
	int noOfDogs = 0;
	int noOfDragons = 0;
	int noOfBees = 0;
	Dog *dogs[MAXDOGS];
	Dragon *dragons[MAXDRAGONS];
	Bee *bees[MAXBEES];
	// Add array of cats and rabbits

	// Technical object grouping console operations
	Console &console;

public:
	// Constructors
	Playground(Console &console);
	~Playground();

	void AddDog(Dog &dog);
	void AddDragon(Dragon &dragon);
	void AddBee(Bee &bee);
	// add AddCat AddRabbit
	void AnimalsDoDraw();
	void AnimalsDoAction();
	void Simulate();
};

