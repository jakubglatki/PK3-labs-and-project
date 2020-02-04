#include "stdafx.h"
#include "Playground.h"
using namespace std;

//pragma tylko do zwijania
#pragma region Constructors
Playground::Playground(Console &console): console(console)
{}

Playground::~Playground()
{}
#pragma endregion


#pragma region Methods: Playground manipulation
void Playground::AddDog(Dog &dog)
{
	if (noOfDogs < MAXDOGS)
		dogs[noOfDogs++] = &dog;
}

// add methods for adding cats and rabbits

void Playground::AddDragon(Dragon &dragon)
{
	if (noOfDragons < MAXDRAGONS)
		dragons[noOfDragons++] = &dragon;
}

void Playground::AddBee(Bee &bee)
{
	if (noOfBees < MAXBEES)
		bees[noOfBees++] = &bee;
}
void Playground::AnimalsDoDraw()
{
	for (int i = 0; i < noOfDogs; i++)
		dogs[i]->DoDraw(console);
	// add action for drawing cats and rabbits
	for (int i = 0; i < noOfDragons; i++)
		dragons[i]->DoDraw(console);
	for (int i = 0; i < noOfBees; i++)
		bees[i]->DoDraw(console);
}

void Playground::AnimalsDoAction()
{
	for (int i = 0; i<noOfDogs; i++)
		dogs[i]->DoAction(console);
	// add action for cats and rabbits
	for (int i = 0; i<noOfDragons; i++)
		dragons[i]->DoAction(console);
	for (int i = 0; i < noOfBees; i++)
		bees[i]->DoAction(console);
}

void Playground::Simulate()
{
	DWORD currentTickCount;
	DWORD lastDrawTickCount = 0;

	while (!console.KeyPressed(VK_ESCAPE))
	{
		currentTickCount = GetTickCount();				//tickcount in ms

		if (currentTickCount - lastDrawTickCount > 20)	// 50 frames per second
		{
			AnimalsDoAction();
			console.CopyBackgroundToPlayground();
			AnimalsDoDraw();
			console.CopyPlaygroundToScreen();

			lastDrawTickCount = GetTickCount();
		}
	}
}
#pragma endregion

