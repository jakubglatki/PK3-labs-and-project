#pragma once
#pragma once
#include "AnimalSprite.h"
#include "Console.h"

class Bee : public AnimalSprite
{
private:

	const Action actionInfo[5] = {
		{ 01, "thinking",   1, &AnimalSprite::ActionThinking },   //directory of run is changing 
		{ 49, "flying",  100, &AnimalSprite::ActionMoving },
		{ 30, "pollen spreading",  60, &AnimalSprite::ActionSpecial },
		{ 20, "sleeping", 50, &AnimalSprite::ActionSleeping },
	};
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

	void ActionThinking(Console &console);
	void DontLeaveMap(Console &console);
	void ActionMoving(Console &console);
	void ActionSpecial(Console &console);
    void ActionSleeping(Console &console);

};

