#include "stdafx.h"
#include "Bee.h"

using namespace std;

#pragma region Constructors
Bee::Bee() : Bee("Anonymous", 0, true, 0)
{}

Bee::Bee(string name) : Bee(name, 0, true, 0)
{}

Bee::Bee(std::string name, int age, bool isMale, WORD color) : AnimalSprite(name, age, isMale, color)
{}

Bee::Bee(const Bee &Bee) : AnimalSprite(Bee)
{}

Bee::Bee(Bee &&Bee) : AnimalSprite(move(Bee))
{}

Bee::~Bee()
{}
#pragma endregion

#pragma region Operators
Bee& Bee::operator= (const Bee& Bee)
{
	AnimalSprite::operator= (Bee);
	return *this;
}

Bee& Bee::operator= (Bee&& Bee)
{
	AnimalSprite::operator= (std::move(Bee));
	return *this;
}
#pragma endregion


#pragma region Virtual functions
AnimalSprite::Action Bee::ActionInfo(int index)
{
	return actionInfo[index];
}

string Bee::DoGetInfo()
{
	return "Bee " + AnimalSprite::DoGetInfo();
}
#pragma endregion


#pragma region Metods: actions



void Bee::ActionThinking(Console &console)
{
	dx = -0.5f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
	dy = -0.5f + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
}

void Bee::DontLeaveMap(Console &console) {
	if (x + dx < 0 || x + dx > console.GetWidth())
		dx = -dx;

	if (y + dy < 0 || y + dy > console.GetHeight())
		dy = -dy;

}

void Bee::ActionMoving(Console &console)
{
	DontLeaveMap(console);

	x += dx;
	y += dy;
}

void Bee::ActionSpecial(Console &console)
{
	//if (x + dx < 0 || x + dx > console.GetWidth() ||y + dy < 0 || y + dy >console.GetHeight()) {
		//for (int i = 5; i <= 21;i = i + 5) {
	for (int j = 0;j < 8;j += 2) {
		for (int k = 1;k < 8;k += 2) {
			for(int l=0;l<8;l++){
				if (actionActualFrame == 20 + j) {
					console.DrawRectangleOnBackground((short)x + j, (short)y, 0, -1, BACKGROUND_RED | BACKGROUND_BLUE);
					console.DrawRectangleOnBackground((short)x + k, (short)y, 0, -1, BACKGROUND_GREEN);
					console.DrawRectangleOnBackground((short)x+l, (short)y + 1, 0, -1, BACKGROUND_GREEN);
				}
			}
		}
	}
	for (int j = 0;j < 8;j += 2) {
		for (int k = 1;k < 8;k += 2) {
			for (int l = 0;l < 8;l++) {
				if (actionActualFrame == 30 + j) {
					console.DrawRectangleOnBackground((short)x + 6 - j, (short)y + 2, 0, -1, BACKGROUND_RED | BACKGROUND_BLUE);
					console.DrawRectangleOnBackground((short)x + k, (short)y + 2, 0, -1, BACKGROUND_GREEN);
					console.DrawRectangleOnBackground((short)x + l, (short)y + 3, 0, -1, BACKGROUND_GREEN);
				}
			}
		}
	}
	for (int j = 0;j < 8;j += 2) {
		for (int k = 1;k < 8;k += 2) {
			for (int l = 0;l < 8;l++) {
				if (actionActualFrame == 40 + j) {
					console.DrawRectangleOnBackground((short)x + j, (short)y + 4, 0, -1, BACKGROUND_RED | BACKGROUND_BLUE);
					console.DrawRectangleOnBackground((short)x + k, (short)y + 4, 0, -1, BACKGROUND_GREEN);
					console.DrawRectangleOnBackground((short)x + l, (short)y + 5, 0, -1, BACKGROUND_GREEN);
				}
			}
		}
	}	
	for (int j = 0;j < 8;j += 2) {
		for (int k = 1;k < 8;k += 2) {
			if (actionActualFrame == 50 + j) {
				for (int l = 0;l < 8;l++) {
					console.DrawRectangleOnBackground((short)x + 6 - j, (short)y + 6, 0, -1, BACKGROUND_RED | BACKGROUND_BLUE);
					console.DrawRectangleOnBackground((short)x + k, (short)y + 6, 0, -1, BACKGROUND_GREEN);
					console.DrawRectangleOnBackground((short)x + l, (short)y + 7, 0, -1, BACKGROUND_GREEN);
				}
			}
		}
	}
}

void Bee::ActionSleeping(Console &console)
{
	if (actionActualFrame % 20 == 0) actionText = actionText + "..bzzz";

}



#pragma endregion
