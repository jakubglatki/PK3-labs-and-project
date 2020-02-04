#pragma once
#include<random>
#include<chrono>
#include<iostream>
#include "team.h"
#include "table.h"

int luck();                     //determines if team can score more than 3 goals in game

int random(int homeAdvantage);  //team that playes at home as a chance to score 1 more goal

int anotherLuck();             //anotherLuck makes averagely once in 4 games stronger team not having advantage from being stronger

void simulateMatch(Table *team1, Table *team2);