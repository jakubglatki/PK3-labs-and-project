#pragma once
#pragma once
#include "Animal.h"
#include "Console.h"

class Bee : public Animal
{
private:

	const Action actionInfo[5] = {
		{ 01, "thinking",   1, &Animal::ActionThinking },   //directory of run is changing 
		{ 49, "flying",  100, &Animal::ActionMoving },
		{ 30, "pollen spreading",  60, &Animal::ActionSpecial },
		{ 20, "sleeping", 50, &Animal::ActionSleeping },
	};
public:
	// konstruktory
	Bee();
	Bee(const Bee &Bee);
	Bee(Bee &&Bee);
	Bee(std::string name);
	Bee(std::string name, std::string species, int age, bool isMale, WORD color);
	~Bee();

	// Operatory
	Bee& operator= (const Bee &Bee);
	Bee& operator= (Bee &&Bee);

	// Bee virtual actions
	virtual std::string GetSpecies();
	virtual std::string DoGetInfo();

	// Action implementation
	Action ActionInfo(int);

	void ActionThinking(Console &console);
	void DontLeaveMap(Console &console);
	void ActionMoving(Console &console);
	void ActionSpecial(Console &console);
    void ActionSleeping(Console &console);

};

