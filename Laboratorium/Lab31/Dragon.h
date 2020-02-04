#pragma once
#include "Animal.h"
#include "Console.h"
#include <string>

class Dragon : public Animal
{
private:
	typedef void(Dragon::*ActionFunction)(Console&);
	struct Action
	{
		int probability;
		std::string actionText;
		int frameNumber;   //50 is 1 sec
		ActionFunction actionFunction;
	};
	const Action actionInfo[5] = {
		{ 01, "thinking",   1, &Dragon::ActionThinking },   //directory of run is changing 
		{ 40, "flying",  200, &Dragon::ActionMoving },
		{ 20, "fire-breathing",  100, &Dragon::ActionSpecial },
		{ 39, "sleeping", 100, &Dragon::ActionSleeping },
	};
	ActionFunction currentActionFunction = &Dragon::ActionThinking;
	int actionActualFrame = 0;
	int actionLastFrame = 1;

public:
	// konstruktory
	Dragon();
	Dragon(const Dragon &Dragon);
	Dragon(Dragon &&Dragon);
	Dragon(std::string name);
	Dragon(std::string name, int age, bool isMale, WORD color);
	~Dragon();

	// Operatory
	Dragon& operator= (const Dragon &Dragon);
	Dragon& operator= (Dragon &&Dragon);

	// Dragon virtual actions
	virtual std::string DoGetInfo();

	// Action implementation
	Action ActionInfo(int);
	void DoAction(Console &console);

	void ActionThinking(Console &console);
	void ActionMoving(Console &console);
	void ActionSpecial(Console &console);
	void ActionSleeping(Console &console);

};

#pragma once
