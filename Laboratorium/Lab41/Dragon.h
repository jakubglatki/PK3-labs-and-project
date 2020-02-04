#pragma once
#include "Animal.h"
#include "Console.h"
#include <string>

class Dragon : public Animal
{
private:
	const Action actionInfo[5] = {
		{ 01, "thinking",   1, &Animal::ActionThinking },   //directory of run is changing 
		{ 40, "flying",  200, &Animal::ActionMoving },
		{ 20, "fire-breathing",  100, &Animal::ActionSpecial },
		{ 39, "sleeping", 100, &Animal::ActionSleeping },
	};

public:
	// konstruktory
	Dragon();
	Dragon(const Dragon &Dragon);
	Dragon(Dragon &&Dragon);
	Dragon(std::string name);
	Dragon(std::string name, std::string species, int age, bool isMale, WORD color);
	~Dragon();

	// Operatory
	Dragon& operator= (const Dragon &Dragon);
	Dragon& operator= (Dragon &&Dragon);

	// Dragon virtual actions
	virtual std::string GetSpecies();
	virtual std::string DoGetInfo();

	// Action implementation
	Action ActionInfo(int);

	void ActionThinking(Console &console);
	void ActionMoving(Console &console);
	void ActionSpecial(Console &console);
	void ActionSleeping(Console &console);

};

#pragma once
