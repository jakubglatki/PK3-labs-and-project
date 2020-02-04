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
void Playground::AddAnimal(Animal &animal)
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


void Playground::Chase(int bee, int dog)
{
	// dog follows rabbit
	if (this->animals[bee]->GetXCoordinate() > this->animals[dog]->GetXCoordinate())
	{
		this->animals[dog]->SetXCoordinate(0.1);
	}
	else
	{
		this->animals[dog]->SetXCoordinate(-0.1);
	}

	if (this->animals[bee]->GetYCoordinate() > this->animals[dog]->GetYCoordinate())
	{
		this->animals[dog]->SetYCoordinate(0.1);
	}
	else
	{
		this->animals[dog]->SetYCoordinate(-0.1);
	}
	this->animals[dog]->SetActionText("chasing");
}

bool Playground::Stinging(int dog, int bee)
{
	if (abs(this->animals[bee]->GetXCoordinate() - this->animals[dog]->GetXCoordinate()) == 0)
	{
		if (abs(this->animals[bee]->GetYCoordinate() - this->animals[dog]->GetYCoordinate()) == 0)
		{
			animals[dog]->SetActionText("stinged");
			animals[dog]->ActionMoving(console);
			return true;
		}
	}
	return false;
}

bool Playground::Detection()
{
	for (int i = 0; i < noOfAnimals; i++)
	{
		for (int j = 0; j < noOfAnimals; j++)
		{
			if (animals[i]->GetSpecies() == "Bee")
			{
				if (animals[j]->GetSpecies() == "Dog")
				{

					if (abs(animals[i]->GetXCoordinate() - animals[j]->GetXCoordinate()) < 2)
					{
						if (abs(animals[i]->GetYCoordinate() - animals[j]->GetYCoordinate()) < 2)
						{
							return true;
						}
					}
				}
			}
		}
	}
	return false;
}

int Playground::BeeSeen()
{
	for (int i = 0; i < noOfAnimals; i++)
	{
		for (int j = 0; j < noOfAnimals; j++)
		{
			if (animals[i]->GetSpecies() == "Bee")
			{
				if (animals[j]->GetSpecies() == "Dog")
				{

					if (abs(animals[i]->GetXCoordinate() - animals[j]->GetXCoordinate()) < 2)
					{
						if (abs(animals[i]->GetYCoordinate() - animals[j]->GetYCoordinate()) < 2)
						{
							return j;
						}
					}
				}
			}
		}
	}
	return -1;
}





void Playground::Simulate()
{
	DWORD currentTickCount;
	DWORD lastDrawTickCount = 0;

	int chasingDog = 0;
	int bees = 1;
	bool stinged = false;

	while (!console.KeyPressed(VK_ESCAPE))
	{
		currentTickCount = GetTickCount();				//tickcount in ms

		if (currentTickCount - lastDrawTickCount > 20)	// 50 frames per second
		{
			//to do
			//AnimalsDoNotification();
			if (BeeSeen()==true)
			{
				chasingDog = Detection();
			}
			if (!stinged)
			{
				if (!Stinging(chasingDog, bees))
				{
					Chase(chasingDog, bees);
				}
				else
				{
					stinged = true;
				}
			}

			AnimalsDoAction();
			console.CopyBackgroundToPlayground();
			AnimalsDoDraw();
			console.CopyPlaygroundToScreen();

			lastDrawTickCount = GetTickCount();
		}
	}
}
#pragma endregion

