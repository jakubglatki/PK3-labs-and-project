#pragma once
#include "teamsPL.h"
#include "match.h"
#include "drawTable.h"

int schedule(int teamNumber);
std::vector<Table> calendar(int teams, int trick, std::vector<Table> *team);
std::vector<Table> makeSchedule(std::vector<Table> *team);