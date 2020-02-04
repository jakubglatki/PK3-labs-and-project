#include "table.h"

//constructors
Table::Table() {
}

Table::Table(int attack, int defence, std::string name) : attack(attack), defence(defence), name(name) {}

Table::Table(int attack, int defence, std::string name, int position, int matchesPlayed, int points, int gamesWon,
	int gamesDrawn, int gamesLost, int goalsScored, int goalsConceded, int goalsDiffrence) : attack(attack), defence(defence),
	name(name), position(position), matchesPlayed(matchesPlayed), points(points), gamesWon(gamesWon),
	gamesDrawn(gamesDrawn), gamesLost(gamesLost), goalsScored(goalsScored), goalsConceded(goalsConceded), goalsDiffrence(goalsDiffrence) {
}

Table::~Table() {
}

//operators

std::ostream &operator<<(std::ostream & out, const Table & team) {

	out << std::left;
	out << "     " << std::setw(20) << team.name << std::setw(8) << team.points << std::setw(8)
		<< team.matchesPlayed << std::setw(8) << team.gamesWon << std::setw(8)
		<< team.gamesDrawn << std::setw(8) << team.gamesLost << std::setw(8) << team.goalsScored << std::setw(7)
		<< team.goalsConceded << std::setw(3) << std::right << team.goalsDiffrence << std::endl;

	return out;
}


std::istream & operator >> (std::istream &in, Table &team)
{
	in >> team.name;
	in >> team.attack;
	in >> team.defence;
	return in;
}



//setters


void Table::setAttack(int attack) {
	this->attack = attack;
}

void Table::setDefence(int defence) {
	this->defence = defence;
}

void Table::setName(std::string name) {
	this->name =name;
}

void Table::setPosition(int position) {
	this->position = position;
}

void Table::setMatchesPlayed(int matchesPlayed) {
	this->matchesPlayed = matchesPlayed;
}

void Table::setPoints(int points) {
	this->points = points;
}

void Table::setGamesWon(int gamesWon) {
	this->gamesWon = gamesWon;
}

void Table::setGamesDrawn(int gamesDrawn) {
	this->gamesDrawn = gamesDrawn;
}

void Table::setGamesLost(int gamesLost) {
	this->gamesLost = gamesLost;
}

void Table::setGoalsScored(int goalsScored) {
	this->goalsScored = goalsScored;
}

void Table::setGoalsConceded(int goalsConceded) {
	this->goalsConceded = goalsConceded;
}

void Table::setGoalsDiffrence(int goalsDiffrence) {
	this->goalsDiffrence = goalsDiffrence;
}

//getters

int Table::getAttack() {
	return attack;
}

int Table::getDefence() {
	return defence;
}

std::string Table::getName() {
	
	return name;
}


int Table::getPosition() {
	return position;
}

int Table::getMatchesPlayed() {
	return matchesPlayed;
}

int Table::getPoints() {
	return points;
}

int Table::getGamesWon() {
	return gamesWon;
}

int Table::getGamesDrawn() {
	return gamesDrawn;
}

int Table::getGamesLost() {
	return gamesLost;
}

int Table::getGoalsScored() {
	return goalsScored;
}

int Table::getGoalsConceded() {
	return goalsConceded;
}

int Table::getGoalsDiffrence() {
	return goalsDiffrence;
}

//others

void Table::makeChangesInTable(int goalsFor, int goalsAgainst) {
	
	this->matchesPlayed++;
	this->goalsScored += goalsFor;
	this->goalsConceded += goalsAgainst;
	this->goalsDiffrence += (goalsFor - goalsAgainst);

	if (goalsFor > goalsAgainst) {
		this->points += 3;
		this->gamesWon++;
	}
	else if (goalsFor == goalsAgainst) {
		this->points += 1;
		this->gamesDrawn++;
	}
	else if (goalsFor < goalsAgainst) {
		this->points += 0;
		this->gamesLost++;
	}
}
