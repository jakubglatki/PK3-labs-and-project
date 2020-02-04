#include "stdafx.h"
#include "Dog.h"
using namespace std;


//Konstruktory
Dog::Dog()
{
	Dog::name = "Anonymous";
	Dog::breed = "Mongrel";
	std::cout << "Constructor[parameterless]: " << GetInfo() << " created" << std::endl;
};

Dog::Dog(const std::string &name)
{
	Dog::name = name;
	Dog::breed = "Mongrel";
	std::cout << "Constructor[one-parameter]: " << GetInfo() << " created" << std::endl;
};

Dog::Dog(const std::string &name, int age, const std::string &breed, int power, int aggresion, bool isAlive)
{
	Dog::name = name;
	Dog::age = age;
	Dog::breed = breed;
	Dog::power = power;
	Dog::aggresion = aggresion;
	Dog::isAlive = isAlive;
	std::cout << "Constructor[multiparameter]: " << GetInfo() << " created" << std::endl;
};

Dog::Dog(const Dog &dog)
{
	Dog::name = dog.name;
	Dog::age = dog.age;
	Dog::breed = dog.breed;
	Dog::power = dog.power;
	Dog::aggresion = dog.aggresion;
	Dog::isAlive = dog.isAlive;
	std::cout << "Constructor[copy]: " << GetInfo() << " created" << std::endl;
}
//Akcesory

// Akcesory - setters
void Dog::SetName(std::string name)
{
	Dog::name = name;
	std::cout << name << " name modified to " << name << " by setter function" << std::endl;
};
void Dog::SetBreed(std::string breed)
{
	Dog::breed = breed;
	std::cout << name << " breed modified to " << breed << " by setter function" << std::endl;
};
void Dog::SetPower(int power)
{
	if (power >= 0) Dog::power = power;
	else Dog::power = 0;
	std::cout << name << " power modified to " << Dog::power << " by setter function" << std::endl;
};
void Dog::SetAggresion(int aggresion)
{
	Dog::aggresion = aggresion;
};
void Dog::SetAge(int age)
{
	Dog::age = age;
};

// Akcesory - getters
std::string Dog::GetName() const
{
	return Dog::name;
};
std::string Dog::GetBreed() const {
	return Dog::breed;
};
int Dog::GetPower() const
{
	return Dog::power;
};
int Dog::GetAggresion() const
{
	return Dog::aggresion;
};
int Dog::GetAge() const
{
	return Dog::age;
};


// Debug methods

string Dog::GetInfo()
{
	string liveDesc = isAlive ? "Dog " : "Dead dog";
	string infoString = liveDesc + GetName() + " of breed " + GetBreed() + " and age " + std::to_string(age) + " and power " + std::to_string(power);
	return infoString;
}

void Dog::PrintInfo()
{
	cout << GetInfo() << endl;
}

