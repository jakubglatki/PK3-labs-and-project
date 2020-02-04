#include "drawTable.h"

std::vector<Table> sortTable(std::vector<Table>* teams)
{
	std::vector<Table> team = *teams;
	int size = team.size();

	for (int i = 0;i <= size;i++) {
		for (int j = 1;j< size-i;j++) {
			if (team[j - 1].getPoints() < team[j].getPoints()) {
				std::swap(team[j - 1], team[j]);
			}
			else if (team[j - 1].getPoints() == team[j].getPoints()) {
				if (team[j - 1].getGoalsDiffrence() < team[j].getGoalsDiffrence()) {
					std::swap(team[j - 1], team[j]);
				}
				else if (team[j - 1].getGoalsDiffrence() == team[j].getGoalsDiffrence()) {
					if (team[j - 1].getGoalsScored() < team[j].getGoalsScored()) {
						std::swap(team[j - 1], team[j]);
					}
				}
			}
		}
	}


	return team;
}

std::vector < Table> drawTable(std::vector<Table> *teams) {
	std::vector<Table> team = *teams;
	int size = team.size();
	team = sortTable(&team);

	tableDataText();
	for (int i = 0;i < size;i++) {
	

		std::cout << std::left;
		std::cout << "     " << std::setw(5) << i + 1;
		std::cout << team[i];
	}

	abbreviationMeaningText();

	saveTableToFile(team);

	team.clear();

	Menu menu;     //I'm not sure if it's optimal, but found it as the best way to start another program loop
	runMenu(menu);

	return team;
}