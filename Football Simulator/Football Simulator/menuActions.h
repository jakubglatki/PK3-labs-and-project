#pragma once
#include "menu.h"
#include "menuText.h"
#include "teamsPL.h"
#include "userTeams.h"
#include "table.h"
#include "drawTable.h"
#include "schedule.h"
#include <Windows.h>


void clearScreen();


bool isEscape(const KEY_EVENT_RECORD key);
// returns true ==> finish program

bool getConChar(KEY_EVENT_RECORD& krec);
//waiting for keyboard hit

bool isFinished(const menuType currentType, const Menu menu);
// isFinished checks if program did his job 
// returns true ==> finish program
// returns false ==> user chose 'back'

void mainMenuAction(Menu & menu, KEY_EVENT_RECORD & key);

void PremierLeagueMenuAction(Menu & menu);

void OwnTeamsMenuAction(Menu & menu);

void switchMenu(menuType & currentType, Menu & menu, KEY_EVENT_RECORD & key);
// function checks menuType and calls the appropriate functions

void chooseAction(Menu & menu, KEY_EVENT_RECORD & key);
// function showing menu and moves arrow until the user enter

void runMenu(Menu & menu);
