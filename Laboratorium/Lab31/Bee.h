#pragma once
#pragma once
#include "Animal.h"
#include "Console.h"

class Bee : public Animal
{
private:
	typedef void(Bee::*ActionFunction)(Console&);
	struct Action
	{
		int probability;
		std::string actionText;
		int frameNumber;   //50 is 1 sec
		ActionFunction actionFunction;
	};
	const Action actionInfo[5] = {
		{ 01, "thinking",   1, &Bee::ActionThinking },   //directory of run is changing 
		{ 50, "flying",  100, &Bee::ActionMoving },
		{ 49, "pollen spreading",  60, &Bee::ActionSpecial },
	};
	ActionFunction currentActionFunction = &Bee::ActionThinking;
	int actionActualFrame = 0;
	int actionLastFrame = 1;

public:
	// konstruktory
	Bee();
	Bee(const Bee &Bee);
	Bee(Bee &&Bee);
	Bee(std::string name);
	Bee(std::string name, int age, bool isMale, WORD color);
	~Bee();

	// Operatory
	Bee& operator= (const Bee &Bee);
	Bee& operator= (Bee &&Bee);

	// Bee virtual actions
	virtual std::string DoGetInfo();

	// Action implementation
	Action ActionInfo(int);
	void DoAction(Console &console);

	void ActionThinking(Console &console);
	void DontLeaveMap(Console &console);
	void ActionMoving(Console &console);
	void ActionSpecial(Console &console);
};

