#include "communication.h"

void noOfTeamsText(){
	std::cout <<std::endl<< " How many teams do you want to have in your league? You can choose any number beetween 3 and 100" <<
		std::endl << " Number of teams: ";
}

void tooManyTeamsText()
{
	std::cout << std::endl << " You've choosed too many teams. Choose number beetween 3 and 100 (using numbers, not letters)" << std::endl<<" ";
}

void notEnoughTeamsText()
{
	std::cout << std::endl << " You've choosed wrong number of teams. Choose number beetween 3 and 100 (using numbers, not letters)" << std::endl<<" ";
}

void goodNumberOfTeamsText()
{
	std::cout << std::endl << " Now you have to give each of your teams name (it has to have at least 1 and less than 20 spaces),"<<std::endl
		<<" attack and defence parameter- it has to be number beetween 1 and 5, the team with best attack should have 5 etc." ;
}

void getAttackText()
{
	std::cout << std::endl << " Attack: ";
}

void getDefenceText()
{
	std::cout << std::endl << " Defence: ";
}

void getNameText()
{
	std::cout << std::endl << " Name: ";
}

void wrongAttackParametrText()
{
	std::cout << std::endl << " You need to choose value of attack beetween 1 and 5. Put in correct value of attack"<<std::endl
		<<" Attack: ";
}

void wrongDefenceParametrText()
{
	std::cout << std::endl << " You need to choose value of defence beetween 1 and 5. Put in correct value of defence."<<std::endl
		<<" Defence: ";
}

void wrongNameText()
{
	std::cout << std::endl << " Your team's name must have at least 1 and less than 20 spaces. This team's name will be shortened.";
}

void getTeamNumberText(int i)
{
	std::cout << std::endl << std::endl << " Team " << i;
}

void wrongThingsWithTeamsText(int numberOfTeams)
{
	std::cout << std::endl << std::endl << std::endl << " You putted something wrong in " << numberOfTeams << " of your teams. Put their parametrs again." <<
		std::endl << " Remember, that attack and defence must have value beetween 1 and 5 and team name must have beetween 1 and 20 spaces";
}

void tableDataText()
{
	std::cout << std::endl << std::endl <<
		std::setw(10) << "Position" << std::setw(8) << "Team" << std::setw(22) << "Points" << std::setw(8) << "Played" << std::setw(7)
		<< "Wins" << std::setw(9) << "Draws" << std::setw(8) << "Loses" << std::setw(5) << "GS" << std::setw(8)
		<< "GC" << std::setw(8) << "GD" << std::endl << std::endl;
}

void abbreviationMeaningText()
{
	std::cout << std::endl << std::endl << "\t"<<" GS- Goals Scored" << std::endl
		<< "\t" << " GC- Goals Conceded" << std::endl << "\t" << " GD- Goals Diffrence";
}

void askingForFileNameText()
{
	std::cout << std::endl << std::endl << std::endl << "    Put in name of the file that you want to save your table into. ";
	std::cout <<std::endl << "    For example, if you will name your file 'table' you will be able to find your table it in 'table.txt'";
	std::cout << std::endl << std::endl<<"    File name: ";
}

void askingForFileNameForTeamsText()
{
	std::cout << std::endl << std::endl << "    Put in name of the file that your teams parametres will be saved for futher usage";
	std::cout << std::endl << "    For example, if you will name your file 'teams' you will be able to find your teams it in 'teams.txt'";
	std::cout << std::endl << "      File name: ";
}

void getFileNameText() 
{
	std::cout << std::endl << std::endl << "    Put in name of the file that you want to load your teams from." <<
		"    You can try it out putting in 'bundesliga.txt'";
}