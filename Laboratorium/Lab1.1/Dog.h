#pragma once

class Dog
{
private:
	std::string name;
	std::string breed;
	int power = 0;
	int aggresion = 0;
	int age = 0;
	bool isMale = true;
	bool isAlive = true;

public:
	// dodaæ konstruktory i destruktor
	Dog();
	Dog(const std::string &name);
	Dog(const std::string &name, int age, const std::string &breed, int power, int aggresion, bool isAlive);
	Dog(const Dog &dog);
	~Dog() 
	{
		std::cout << "Destructor: " << GetInfo() << " deleted" << std::endl;
	};
	// Akcesory - setters
	void SetName(std::string name);
	void SetBreed(std::string breed);
	void SetPower(int power);
	void SetAggresion(int aggresion);
	void SetAge(int age);

	// Akcesory - getters
	std::string GetName() const;
	std::string GetBreed() const;
	int GetPower() const;
	int GetAggresion() const;
	int GetAge() const;

	// Debug info
	std::string GetInfo();
	void PrintInfo();
};

