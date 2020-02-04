#pragma once
#include "AnimalSprite.h"
#include "Console.h"

class Dragon : public AnimalSprite
{
private:
	const Action actionInfo[5] = {
		{ 01, "thinking",   1, &AnimalSprite::ActionThinking },   //directory of run is changing 
		{ 40, "flying",  200, &AnimalSprite::ActionMoving },
		{ 20, "fire-breathing",  100, &AnimalSprite::ActionSpecial },
		{ 39, "sleeping", 100, &AnimalSprite::ActionSleeping },
	};

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

	void ActionThinking(Console &console);
	void ActionMoving(Console &console);
	void ActionSpecial(Console &console);
	void ActionSleeping(Console &console);

};

#pragma once
