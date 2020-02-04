#include "saveTableToFile.h"

void saveTableToFile(std::vector<Table> & teams) {
	std::vector<Table> team = teams;
	int size = team.size();

	std::string fileName;
	askingForFileNameText();
	std::getline(std::cin, fileName);
	fileName += ".txt";

	std::ofstream file(fileName);

	file << std::setw(10) << "Position" << std::setw(8) << "Team" << std::setw(22) << "Points" << std::setw(8) << "Played" << std::setw(7)
		<< "Wins" << std::setw(9) << "Draws" << std::setw(8) << "Loses" << std::setw(5) << "GS" << std::setw(8)
		<< "GC" << std::setw(8) << "GD" << std::endl << std::endl;

	for (int i = 0;i < size;i++) {


		file << std::left;
		file << "     " << std::setw(5) << i + 1;
		file << team[i];
	}

	file.close();
}

void saveTeamsToFile(std::vector<Table> & teams) {
	std::vector<Table> team = teams;
	int size = team.size();

	std::string fileName;
	askingForFileNameForTeamsText();

	std::getline(std::cin, fileName);
	fileName += ".txt";

	std::ofstream file(fileName);
	
	for (int i = 0;i < size;i++) {
		file << team[i].getName() << std::endl<<team[i].getAttack()<<std::endl<< team[i].getDefence()<<std::endl;
	}
	file.close();
}