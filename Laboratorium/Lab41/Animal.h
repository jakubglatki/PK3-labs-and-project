#pragma once
#include "Console.h"

class Animal
{
public:
	float x,y;
	float dx=0.0f, dy=0.0f;
	WORD color = 0;
	int actionActualFrame = 0;
	int actionLastFrame = 1;

protected:
	typedef void (Animal::*ActionFunction)(Console&);
	struct Action
	{
		int probability;
		std::string actionText;
		int frameNumber;
		ActionFunction actionFunction;
	};
	ActionFunction currentActionFunction = &Animal::ActionThinking;

	std::string name;
	std::string species;
	std::string actionText;
	int age = 0;
	bool isMale = true;
	bool isAlive = true;
	char *imageData = nullptr;

public:
	// Constructors and destructor
	Animal();
	Animal(std::string, std::string species, int, bool, WORD);
	Animal(const Animal &);
	Animal(Animal &&);
	~Animal();
	
	// Akcesory - setters
	void SetName(std::string);
	void SetAge(int);
	void SetImage(char *imageData);
	void SetXCoordinate(int x);
	void SetYCoordinate(int y);
	void SetActionText(std::string text);

	// Akcesory - getters
	std::string GetName() const;
	WORD GetColor() const;
	int GetAge() const;
	char* GetImage() const;
	int GetXCoordinate() const;
	int GetYCoordinate() const;

	// Operatory
	Animal& operator= (const Animal& animal); 
	Animal& operator= (Animal&& animal); 

	// Animal actions ta
	virtual void DoDraw(Console &);
	virtual void DoAction(Console &);
	virtual std::string DoGetInfo();
	virtual std::string GetSpecies();

	//to do
	//virtual void DetectedAnimal(const Animal &animal);

	// Actions to be implemented in derived classes
	virtual Action ActionInfo(int index) = 0;
	virtual void ActionThinking(Console &console) = 0;
	virtual void ActionMoving(Console &console) = 0;
	virtual void ActionSpecial(Console &console) = 0;
	virtual void ActionSleeping(Console &console) = 0;

};

