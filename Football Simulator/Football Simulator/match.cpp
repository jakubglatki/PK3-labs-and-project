#include "match.h"

int luck()
{
	std::default_random_engine engine;
	std::uniform_real_distribution <double> number;
	auto time = std::chrono::system_clock::now();
	auto i_value = time.time_since_epoch();
	engine.seed(i_value.count());
	int value = number(engine) * 4;
	//std::cout<<"luck: " << value << std::endl;

	return value;
}

int random(int homeAdvantage)
{
	std::default_random_engine engine;
	std::uniform_real_distribution <double> number;
	auto time = std::chrono::system_clock::now();
	auto i_value = time.time_since_epoch();
	engine.seed(i_value.count());
	int lucky= luck();
	int value;
	if (lucky == 1) {
		value = number(engine) * (4 + homeAdvantage);
	}
	else {
		value = number(engine) * (2 + homeAdvantage);
	}
	//std::cout<<"random " << value << std::endl;

	return value;
}

int anotherLuck() {
	std::default_random_engine engine;
	std::uniform_real_distribution <double> number;
	auto time = std::chrono::system_clock::now();
	auto i_value = time.time_since_epoch();
	engine.seed(i_value.count());
	int value = number(engine) * 4;
	//std::cout << "another luck: " << value << std::endl;

	return value;
}



void simulateMatch(Table *team1,Table *team2) {
	int homeScore, awayScore, lucky;
	Table teamA = *team1;
	Table teamB = *team2;
		homeScore = teamA.getAttack() -teamB.getDefence();
		lucky = anotherLuck();
		if (homeScore < 0||lucky==0) {
			homeScore=random(1);
			if (homeScore < 0) {
				homeScore = 0;
			}
		}
		else homeScore += random(1);
	    awayScore = teamB.getAttack() - teamA.getDefence();
		lucky = anotherLuck();      //need diffrent luck value for both teams, statisticaly once in every 4 games better teams doesn't have 1-2 goal in advance
		if (awayScore < 0||lucky==0) {
			awayScore = random(0);
			if (awayScore < 0) {
				awayScore = 0;
			}
		}
		else awayScore += random(0);
		std::cout <<homeScore << " - " << awayScore;
	
		team1->makeChangesInTable (homeScore, awayScore);
		team2->makeChangesInTable (awayScore, homeScore);
}