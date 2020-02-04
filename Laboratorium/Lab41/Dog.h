#pragma once
#include "Animal.h"
#include "Console.h"

class Dog : public Animal
{
private:
	const Action actionInfo[5] = {
		{ 1, "thinking", 1, &Animal::ActionThinking },
		{ 60, "running", 200, &Animal::ActionMoving },
		{ 20, "pissing", 100, &Animal::ActionSpecial },
		{ 19, "sleeping", 100, &Animal::ActionSleeping },
	};
public:
	// konstruktory
	Dog();
	Dog(const Dog &dog);
	Dog(Dog &&dog);
	Dog(std::string name, std::string species);
	Dog(std::string name, std::string species, int age, bool isMale, WORD color);
	~Dog();

	// Operatory
	Dog& operator= (const Dog &dog);
	Dog& operator= (Dog &&dog); 
		
	// Dog virtual actions
	virtual std::string GetSpecies();
	virtual std::string DoGetInfo();

	// Action implementation
	Action ActionInfo(int);
	void ActionThinking(Console &console);
	void ActionMoving(Console &console);
	void ActionSpecial(Console &console);
	void ActionSleeping(Console &console);
};

