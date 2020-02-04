#include "stdafx.h"
#include "Playground.h"
using namespace std;


#pragma region Constructors
Playground::Playground(Console &console): console(console)
{}

Playground::~Playground()
{}
#pragma endregion


#pragma region Methods: Playground manipulation
void Playground::AddAnimal(Sprite &animal)
{
	if (noOfAnimals < MAXANIMALS)
		animals[noOfAnimals++] = &animal;
}

void Playground::AnimalsDoDraw()
{
	for (int i = 0; i < noOfAnimals; i++)
		animals[i]->DoDraw(console);
}


//   to do     ctrl+k+c//ctrl+k+u
//void playground::animalsdonotification()
//{
//	for (int i = 0; i < noofanimals; i++)
//		for (int j = 0;j < noofanimals;j++)
//			if (animals[i].x = .....)
//			{
//				animals[i]->detectedanimal(animal[j])
//
//			}
//}

void Playground::AnimalsDoAction()
{
	for (int i = 0; i<noOfAnimals; i++)
		animals[i]->DoAction(console);
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
			//to do
			//AnimalsDoNotification();

			AnimalsDoAction();
			console.CopyBackgroundToPlayground();
			AnimalsDoDraw();
			console.CopyPlaygroundToScreen();

			lastDrawTickCount = GetTickCount();
		}
	}
}
#pragma endregion

