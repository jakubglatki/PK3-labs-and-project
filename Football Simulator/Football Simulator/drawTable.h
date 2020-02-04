#pragma once
#include "menuActions.h"
#include "communication.h"
#include "table.h"
#include "saveTableToFile.h"

std::vector<Table> sortTable(std::vector<Table>*teams);  //if team has more points than another is placed higher. Than if two teams 
                                                        //have the same number of points team with better Goals Diffrence is higher.
                                                        //Than if their Goals Diffrence is equal the team with more goals scored is higher.
                                                        //Than it's not decided by program
std::vector<Table> drawTable(std::vector<Table> *team);