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

	// create animals
	Dog fafik("Fafik");
	Dog puszek("Puszek");
	Dog borek("Borek");
	Dog reksio("Reksio");


	Dragon tabaluga("Tabaluga", 3, 1, FOREGROUND_RED);
	Dragon szczerbatek("Szczerbatek", 2, 1, FOREGROUND_RED);

	Bee barry("Barry B. Benson", 1, 1, FOREGROUND_RED|FOREGROUND_GREEN);
	// add animals to playground
	playground.AddDog(fafik);
	playground.AddDog(puszek);
	playground.AddDog(borek);
	playground.AddDog(reksio);
	playground.AddDragon(tabaluga);
	playground.AddDragon(szczerbatek);
	playground.AddBee(barry);
	// simulation mail loop
	playground.Simulate();

	return 0;
}

