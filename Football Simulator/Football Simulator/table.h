
#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <iomanip>
#include <utility>

class Table {
private:	
	int attack = 0;		
	int defence = 0;
	std::string name;
	int position = 0;
	int matchesPlayed = 0;
	int points = 0;
	int gamesWon = 0;
	int gamesDrawn = 0;
	int gamesLost = 0;
	int goalsScored = 0;
	int goalsConceded = 0;
	int goalsDiffrence = 0;
public:
	//constructors
	Table();
	Table::Table(int attack, int defence, std::string name); //constructor for making new teams
	Table(int attack, int defence, std::string name, int position, int matchesPlayed, int points, int gamesWon,
		int gamesDrawn, int gamesLost, int goalsScored, int goalsConceded, int goalsDiffrence);
	~Table();


	//operators
	friend std::ostream &operator<<(std::ostream & out, const Table & team);
	friend std::istream &operator>>(std::istream & in, Table &team);

	//setters
	void setAttack(int);
	void setDefence(int);
	void setName(std::string name);
	void setPosition(int);
	void setMatchesPlayed(int);
	void setPoints(int);
	void setGamesWon(int);
	void setGamesDrawn(int);
	void setGamesLost(int);
	void setGoalsScored(int);
	void setGoalsConceded(int);
	void setGoalsDiffrence(int);

	//getters
	int getAttack();
	int getDefence();
	std::string getName();
	int getPosition();
	int getMatchesPlayed();
	int getPoints();
	int getGamesWon();
	int getGamesDrawn();
	int getGamesLost();
	int getGoalsScored();
	int getGoalsConceded();
	int getGoalsDiffrence();

   //others
	void makeChangesInTable(int goalsFor, int goalsAgainst);
};
