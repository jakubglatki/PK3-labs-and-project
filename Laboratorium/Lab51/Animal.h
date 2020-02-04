#pragma once
#include "Console.h"
#include <string>

using namespace std;

class Animal
{
public:

	std::string name;
	int age = 0;
	bool isMale = true;
	bool isAlive = true;
	char *imageData = nullptr;

	Animal(std::string, int, int);
	// Akcesory - setters
	void SetName(std::string);
	void SetAge(int);
	void SetImage(char *imageData);
	std::string GetName() const;
	int GetAge() const;
	char* GetImage() const;
};
