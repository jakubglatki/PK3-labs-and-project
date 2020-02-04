#include "schedule.h"


int match[100][50][2];                           //it gives opportunity to make bigger number of teams later
                                                 //first two dimension determines team, third one says if it is home or away team

int schedule(int teamNumber) {
	int dimension;                                   //dimension remembers first dimension of table
	
	for (int i = 1;i < teamNumber;i++)
	{
		if (i <= teamNumber / 2)
		{
			match[2 * i - 2][0][0] = i;          
			dimension = 2 * i - 2;                         

		}
		else
		{
			match[2 * i - 1 - teamNumber][0][1] = i;      
			dimension = 2 * i - 1 - teamNumber;                 
		}
		int j = i + 1;                          //it's circle system
		for (int k = 1;k <= teamNumber - 2;k++)
		{
			if (j >= teamNumber)
			{
				j = 1;                         //team from last match goes to the first
			}
			if (k <= (teamNumber - 2) / 2)
			{
				match[dimension][k][0] = j;
			}
			else
			{
				match[dimension][teamNumber - 1 - k][1] = j;
			}
			j++;
		}
	}
	for (int i = 0;i < teamNumber;i++) {
		for (int j = 0;j < teamNumber / 2;j++) {
			for (int k = 0;k < 2;k++) {
				return match[i][j][k];
			}
		}
	}
}

std::vector<Table> calendar(int teamsNumber, int trick, std::vector<Table> *team) {
	
	std::vector<Table> teamPointer = *team;
	Table *team1;
	Table *team2;

	std::cout << std::endl;
	int x = 1;                           //those three integries making odd number of teams possible to implement

	int k = 0;                           //team that pauses in given gameweek
	int m = teamsNumber / 2;              //in even gameweeks teams with number 0,1,2 etc. will pause, in odd 
	                                    //teams with number 0+teamsNumber, 1+teamsNumber etc.
	
	for (int i = 1;i <= teamsNumber*2-2;i++)
	{
		std::cout << " Gameweek " << i << ":"<<std::endl;

		if (trick % 2 != 0) {
			x++;
			if (i % 2 == 1) {
				if (x == teamsNumber) {
					k = teamsNumber/2-1;
					m = 0;
				}
				std::cout << "\t" << "(" << teamPointer[k].getName() << ")"<<std::endl;
				k++;
			
			}
			else {
				std::cout << "\t" << "(" << teamPointer[m].getName() << ")"<<std::endl;
				m++;
				
			}

			for (int j = 1;j < teamsNumber / 2;j++) {      

				if (i < teamsNumber) {
					std::cout << "\t" << teamPointer[(match[i - 1][j][0]-1)].getName() << " ";
					team1 = &teamPointer[(match[i - 1][j][0] - 1)];
					team2 = &teamPointer[(match[i - 1][j][1] - 1)];
					simulateMatch(team1, team2);
					team = &teamPointer;
					std::cout << " " << teamPointer[(match[i - 1][j][1]-1)].getName() << std::endl;
				}
					
				else {
					std::cout << "\t" << teamPointer[(match[i - teamsNumber][j][1] -1)].getName() << " ";
					team1 = &teamPointer[(match[i - teamsNumber][j][1] - 1)];
					team2 = &teamPointer[(match[i - teamsNumber][j][0] - 1)];
					simulateMatch(team1, team2);
					team = &teamPointer;
					std::cout << " " << teamPointer[(match[i - teamsNumber][j][0] - 1)].getName() << std::endl;
				}
				
				
			}
			std::cout << std::endl;
		}
		else {

			for (int j = 0;j < teamsNumber / 2;j++) {         

				if (i < teamsNumber) {
					std::cout << "\t" << teamPointer[match[i - 1][j][0]].getName()<<" ";
					team1 = &teamPointer[match[i - 1][j][0]];
					team2 = &teamPointer[match[i - 1][j][1]];
					simulateMatch(team1, team2);
					team = &teamPointer;
					std::cout<< " "<< teamPointer[match[i - 1][j][1]].getName()<<std::endl;
				}
			
				else {
					std::cout << "\t" << teamPointer[match[i - teamsNumber][j][1]].getName() << " ";
					team1 = &teamPointer[match[i - teamsNumber][j][1]];
					team2 = &teamPointer[match[i - teamsNumber][j][0]];
					simulateMatch(team1, team2);
					team = &teamPointer;
					std::cout << " " << teamPointer[match[i - teamsNumber][j][0]].getName() << std::endl;
					
				}
				
			}
			std::cout << std::endl;

		}

	//	drawTable(&teamPointer);
	}
	if (trick % 2 != 0) {
		std::cout << std::endl << " Team in bracket doesn't play in given gameweek";
	}
	return teamPointer;
}



std::vector<Table> makeSchedule(std::vector<Table> *team) {
	
	std::vector<Table> teamsPointer = *team;
	int teamsNumber = teamsPointer.size(); 

	int trick = teamsNumber;  //needed for function calendar for odd number of teams

		if (teamsNumber % 2 == 0) {
			schedule(teamsNumber);
			teamsPointer= calendar(teamsNumber, trick, &teamsPointer);
		}
		else {
			teamsNumber++;
			schedule(teamsNumber);
			teamsPointer= calendar(teamsNumber, trick, &teamsPointer);
		}

		return teamsPointer;
	}