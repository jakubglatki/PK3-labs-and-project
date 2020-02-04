#include "userTeams.h"

std::vector<Table> goodNumberOfTeams(int noOfTeams) {
	clearScreen();
	std::string name;
	int attack, defence;
	std::vector<Table> usersTeam;
	goodNumberOfTeamsText();
	for (int i = 0;i < noOfTeams;i++) {
		getTeamNumberText(i + 1);
		getNameText();
		std::getline(std::cin, name);
		do {
			std::getline(std::cin, name);
			if (name.length() > 20) {
				wrongNameText();
				name.erase(19);
			}
			else if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
			}
		} while (name.length() < 1);

		getAttackText();
		do {
			std::cin >> attack;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
			}
			else {
				if (attack > 5 || attack < 1) {
					wrongAttackParametrText();
				}
			}
		} while (attack > 5 || attack < 1);
		
		getDefenceText();
		do {
			std::cin >> defence;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
			}
			else {
				if (defence > 5 || defence < 1) {
					wrongDefenceParametrText();
				}
			}
		} while (defence > 5 || defence < 1);

				Table name(attack, defence, name);
				usersTeam.insert(usersTeam.begin(), name);
	  }
	std::string forFile;
	std::getline(std::cin, forFile);
	saveTeamsToFile(usersTeam);
	return usersTeam;
}

std::vector<Table> userTeams(Menu menu) {
	if (menu.getIndex() == 0) {
		int noOfTeams;
		bool isEverythingAlright = false;
		noOfTeamsText();
		do {
			std::cin >> noOfTeams;
			if (std::cin.fail()) {
				std::cin.clear();
				std::cin.ignore();
			}
			else {
				if (noOfTeams > 100) {
					tooManyTeamsText();
				}
				else if (!std::cin || noOfTeams < 3) {
					notEnoughTeamsText();
				}

				else {
					std::vector<Table> usersTeam = goodNumberOfTeams(noOfTeams);
					isEverythingAlright = true;
					return usersTeam;
				}
			}
		} while (isEverythingAlright == false);
	}
}











