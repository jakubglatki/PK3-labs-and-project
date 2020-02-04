#include "stdafx.h"
#include "Dog.h"

using namespace std;

#pragma region Constructors
Dog::Dog(): Dog( "Anonymous", "Dog", 0, true, 0)
{}

Dog::Dog(string name, std::string species ) : Dog( name, species, 0, true, 0)
{}

Dog::Dog(std::string name,  std::string species, int age, bool isMale, WORD color): Animal(name, species, age, isMale, color)
{}

Dog::Dog(const Dog &dog) : Animal(dog)
{}

Dog::Dog(Dog &&dog) : Animal(move(dog))
{}

Dog::~Dog()
{}
#pragma endregion

#pragma region Operators
Dog& Dog::operator= (const Dog& dog)
{
	Animal::operator= (dog);
	return *this;
}

Dog& Dog::operator= (Dog&& dog)
{
	Animal::operator= (std::move(dog));
	return *this; 
}
#pragma endregion


#pragma region Virtual functions
Animal::Action Dog::ActionInfo(int index)
{
	return actionInfo[index];
}

std::string Dog::GetSpecies()
{
	return "Dog";
}

string Dog::DoGetInfo()
{
	return "Dog " + Animal::DoGetInfo();
}
#pragma endregion


#pragma region Metods: actions
void Dog::ActionThinking(Console &console)
{
	dx = -0.5f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	dy = -0.5f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Dog::ActionMoving(Console &console)
{
	if (x + dx < 0 || x + dx > console.GetWidth())
		dx = -dx;

	if (y + dy < 0 || y + dy > console.GetHeight())
		dy = -dy;

	x += dx;
	y += dy;
}

void Dog::ActionSpecial(Console &console)
{
	if (actionActualFrame == 20) console.DrawRectangleOnBackground((short) x, (short) y, 1, 1, BACKGROUND_RED | BACKGROUND_GREEN);
	if (actionActualFrame == 80) console.DrawRectangleOnBackground((short) x - 1, (short) y - 1, 3, 3, BACKGROUND_RED | BACKGROUND_GREEN);
}

void Dog::ActionSleeping(Console &console)
{
	if (actionActualFrame % 20 == 0 ) actionText = actionText + "..hrr";
		 
}

#pragma endregion
