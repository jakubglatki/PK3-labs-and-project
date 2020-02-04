#include "stdafx.h"
#include "Dragon.h"

using namespace std;

#pragma region Constructors
Dragon::Dragon() : Dragon("Anonymous", 0, true, 0)
{}

Dragon::Dragon(std::string name) : Dragon(name, 0, true, 0)
{}

Dragon::Dragon(std::string name, int age, bool isMale, WORD color) : AnimalSprite(name, age, isMale, color)
{}

Dragon::Dragon(const Dragon &Dragon) : AnimalSprite(Dragon)
{}

Dragon::Dragon(Dragon &&Dragon) : AnimalSprite(move(Dragon))
{}

Dragon::~Dragon()
{}
#pragma endregion

#pragma region Operators
Dragon& Dragon::operator= (const Dragon& Dragon)
{
	AnimalSprite::operator= (Dragon);
	return *this;
}

Dragon& Dragon::operator= (Dragon&& Dragon)
{
	AnimalSprite::operator= (std::move(Dragon));
	return *this;
}
#pragma endregion


#pragma region Virtual functions
AnimalSprite::Action Dragon::ActionInfo(int index)
{
	return actionInfo[index];
}

string Dragon::DoGetInfo()
{
	return "Dragon " + AnimalSprite::DoGetInfo();
}
#pragma endregion


#pragma region Metods: actions

void Dragon::ActionThinking(Console &console)
{
	dx = -0.5f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	dy = -0.5f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Dragon::ActionMoving(Console &console)
{
	if (x + dx < 0 || x + dx > console.GetWidth())
		dx = -dx;

	if (y + dy < 0 || y + dy > console.GetHeight())
		dy = -dy;

	x += dx;
	y += dy;
}

void Dragon::ActionSpecial(Console &console)
{
	if (actionActualFrame == 20) console.DrawRectangleOnBackground((short)x, (short)y, 1, 1, BACKGROUND_RED);
	if (actionActualFrame == 40) console.DrawRectangleOnBackground((short)x+1, (short)y-1, 2, 3, BACKGROUND_RED);
	if (actionActualFrame == 90) {
		console.DrawRectangleOnBackground((short)x, (short)y, 1, 1, 0);
		console.DrawRectangleOnBackground((short)x + 1, (short)y - 1, 2, 3, 0);
	}
}

void Dragon::ActionSleeping(Console &console)
{
	if (actionActualFrame % 20 == 0) actionText = actionText + "..zzz";

}

#pragma endregion
