#include "stdafx.h"
#include "Dog.h"
using namespace std;

// Zestaw konstruktorów i destruktor

Dog::Dog() : breed(Breed::Mongrel)	// initialize breed field to Breed::Mongrel is no parameter
{
	this->power = Breed::Mongrel.GetPower();
	cout << "Constructor [parameterless]: " << GetInfo() << " created" << endl;
}

Dog::Dog(string name) : name(name), breed(Breed::Mongrel) // initialize breed field to Breed::Mongrel is no parameter
{
	this->power = Breed::Mongrel.GetPower();
	cout << "Constructor [one-parameter]: " << GetInfo() << " created" << endl;
}

Dog::Dog(std::string name, int age, bool isMale, Breed &breed ) : name(name), age(age), isMale(isMale), breed(breed) // what about breed
{
	this->power =breed.GetPower();
	cout << "Constructor [multi-parameter]: " << GetInfo() << " created" << endl;
}

Dog::Dog(const Dog &dog) : name(dog.name), age(dog.age), breed(dog.breed) // what about breed
{
	this->power = dog.breed.GetPower();
	if (dog.imageData)		
	{
		cout << "Constructor [copy]: copying image " << dog.imageData << endl;
		imageData = new char[strlen(dog.imageData) + 1];
		memcpy(imageData, dog.imageData, strlen(dog.imageData) + 1);
	}

	cout << "Constructor [copy]: " << GetInfo() << " created" << endl;
}
      //dog.imageDate iniclialize with nullptr
Dog::Dog(Dog &&dog) : breed(dog.breed)
{
	if (dog.GetImage() != nullptr)
	{ 
		this->SetImage(dog.GetImage()); 
		dog.SetImage(nullptr);       
	}
	std::cout << "moving" << std::endl;
} 


Dog::~Dog()
{
	cout << "Destructor: "<< GetInfo() << " deleted" << endl;
	if (imageData)
	{
		cout << "Destructor: " << GetName() << " image deleted" << endl;
		delete[] imageData;
	}
}

// Zestaw akcesorów - setters
void Dog::SetName(std::string name)
{
	this->name = name;
	cout << GetName() << " name modified to " << this->name << " by setter function" << endl;
}

void Dog::SetBreed(Breed &breed)
{
	this->breed = breed;
 	cout << GetName() << " breed modified to " << this->breed.GetName() << " by setter function" << endl;
}

void Dog::SetPower(int power) {
	this->power = power;
	cout << GetName() << " power modified to " << this->power << " by setter function" << endl;
}

void Dog::SetAge(int age)
{
	this->age = age;
	cout << GetName() << " age modified to " << this->age << " by setter function" << endl;
}

void Dog::SetImage(char *imageData)
{
	cout << GetName() << " image modified to " << imageData << " by setter function" << imageData << endl;
	if (this->imageData ) // != nullptr
		delete[] imageData;

	if (imageData ) //  !=nullptr )
	{
		this->imageData = new char[strlen(imageData) + 1];
		strcpy(this->imageData, imageData);
	}
}

// Zestaw akcesorów - getters
std::string Dog::GetName() const
{
	return name.empty() ? "Anonymous" : name;
}

Breed& Dog::GetBreed() const
{
	// implement
	return this->breed;
}

int Dog::GetPower() const
{
	return power;
}

int Dog::GetAggresion() const
{
	// implement
	return breed.Breed::GetAggression();
}

int Dog::GetAge() const
{
	return age;
}

char* Dog::GetImage() const
{
	return imageData;
}



// operatory
Dog& Dog::operator= (const Dog& dog)
{
	cout << GetName() << " data replaced by " << dog.GetName() << " data by operator=" << endl;

	if (imageData) //  != nullptr
	{
		cout << "operator=: " << GetName() << " image deleted" << endl;
		delete[] imageData;
		imageData = nullptr;
	}

	if (dog.imageData)  // != nullptr
	{
		cout << "operator= copying image " << dog.imageData << " it lasts 5s" << endl;
		imageData = new char[strlen(dog.imageData) + 1];
		memcpy(imageData, dog.imageData, strlen(dog.imageData) + 1);
	}

	name = dog.name;
	age = dog.age;
	breed = dog.breed;
	// what about breed - implement

	return *this;
}
Dog& Dog::operator= (Dog&& dog)
{
	if (this != &dog) {                     //making sure that we will have another object
		if (dog.GetImage() != nullptr) {
			this->SetImage(dog.GetImage());
			dog.SetImage(nullptr);
		}
		this->SetName(dog.GetName());
		this->SetAge(dog.GetAge());
		this->SetBreed(dog.GetBreed());
		this->SetPower(dog.GetPower());
		isMale = dog.isMale;
		isAlive = dog.isAlive;
	}
	return *this;
}




Dog& Dog::operator++ ()					// postfix Dog++; postarzeje siê o rok
{
	age++;
	cout << GetName() << " is now " << GetAge() << " years old; age modified by ++prefix operator" << endl;

	return *this;		// na stos trafi adres obiektu na rzecz którego wywo³ano operacjê
}

Dog Dog::operator++(int)				// postfix Dog++; postarzeje siê o rok
{
	Dog oldDog = *this;
	age++;
	cout << GetName() << " is now " << GetAge() << " years old; age modified by postfix++ operator" << endl;
	return move(oldDog);		// na stos trafi kopia obiektu na rzecz którego wywo³ano operacjê
}

Dog Dog::operator+(const Dog &dog)
{
	if (isMale == dog.isMale)
	{
		cout << "This is simply impossible" << endl;
		exit(1);
	}
	
	Dog puppy("puppy, child of " + name + " & " + dog.name, 0, true, Breed::Mongrel);
   	cout << puppy.GetName() << " of breed " << puppy.breed.GetName() << " and " << puppy.age << " created" << endl;
	return move(puppy);
}

// Debug methods
string Dog::GetInfo()
{
	string imageDesc = imageData ? imageData : "no data";
	string liveDesc = isAlive ? "Dog " : "Dead dog";
	string infoString = liveDesc + GetName() + " age " + std::to_string(age) + " image " + imageDesc + " of "; // add info of breed 
	return infoString;
}

void Dog::PrintInfo()
{
	cout << GetInfo() << endl;
}

std::ostream& operator<< (std::ostream& os, const Dog& dog)
{
	os << dog.GetName();
	return os;
}

Dog Dog::SimulateFightWith(Dog &dog)
{	
		Dog clonedDog = *this;
		clonedDog.SetPower(power - dog.GetPower());

	if (this->power > dog.power) {
		std::cout << this->GetName() << " would've won if this fight was real! Fortunetelly it wasn't" << std::endl;
	}
	else if (dog.power > this->power) {
		std::cout << dog.GetName() << " would've won if this fight was real! Fortunetelly it wasn't" << std::endl;
	}
	else {
		std::cout << "We would've had draw, if there was a real fight. As there wasn't any, we don't" << std::endl;
	}
	return clonedDog;
}

void injuredDog(Dog &dog) {
	if (dog.power < 0) {
		dog.power = 0;
		std::cout << dog.GetName() << " must go to the vet, but surely will be fine :)  Stop making dogs fighting!" << std::endl;
	}
}
// fafik.FightWith(reksio);
void Dog::FightWith(Dog& dog)
{
	int tPower = this->power;
	this->power -= dog.power;
	dog.power -= tPower;
	injuredDog(*this);
	injuredDog(dog);
}


