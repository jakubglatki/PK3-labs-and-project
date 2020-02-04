// Lab 3-1 solution.cpp : Simple game - no function pointers
//

#include "stdafx.h"
#include "Dog.h"
#include "Dragon.h"
#include "Bee.h"
#include "Playground.h"
#include "Console.h"

using namespace std;
#define WIDTH 80
#define HEIGHT 25


int main()
{
	// initialize random generator
	srand((unsigned int) time(0));

	// create console 
	Console console(WIDTH, HEIGHT);

	// create playground for animals
	Playground playground(console);

	vector<Dog> dogs;


	// create animals
	Dog fafik("Fafik", "Dog");
	Dog puszek("Puszek", "Dog");
	Dog borek("Borek","Dog");

	Dragon tabaluga("Tabaluga", "Dragon", 3, 1, FOREGROUND_RED);
	Dragon szczerbatek("Szczerbatek", "Dragon", 2, 1, FOREGROUND_RED);

	Bee barry("Barry B. Benson","Bee",1, 1, FOREGROUND_RED|FOREGROUND_GREEN);
	// add animals to playground
	playground.AddAnimal(fafik);
	playground.AddAnimal(puszek);
	playground.AddAnimal(borek);
	playground.AddAnimal(tabaluga);
	playground.AddAnimal(szczerbatek);
	playground.AddAnimal(barry);

	// simulation mail loop
	playground.Simulate();

	return 0;
}

