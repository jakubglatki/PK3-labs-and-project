#include "stdafx.h"
#include "Animal.h"

using namespace std;

//Animal 
void Animal::SetName(std::string name)
{
	this->name = name;
}

void Animal::SetAge(int age)
{
	this->age = age;
}

void Animal::SetImage(char *imageData)
{
	if (this->imageData) // != nullptr
		delete[] imageData;

	if (imageData)
	{
		imageData = new char[strlen(imageData) + 1];
		memcpy(this->imageData, imageData, strlen(imageData) + 1);
	}
}

std::string Animal::GetName() const
{
	return name.empty() ? "Anonymous" : name;
}

int Animal::GetAge() const
{
	return age;
}

char* Animal::GetImage() const
{
	return imageData;
}
Animal::Animal(std::string _name, int isMale, int isAlive)
{
	this->name = _name;
	this->isMale = isMale;
	this->isAlive = isAlive;
}
