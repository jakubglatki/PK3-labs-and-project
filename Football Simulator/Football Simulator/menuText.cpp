#include "menuText.h"

std::vector<std::string> returnMainMenu()
{
	std::vector<std::string> mainMenuStrings
	{
		"> Simulate Premier League season",
		"  Simulate season with your own teams",
		"  Quit"
	};
	return mainMenuStrings;
}

std::vector<std::string> returnPremierLeagueMenu()
{
	std::vector<std::string> PremierLeagueMenuStrings
	{
		"> Start simulation",
		"  Back"
	};
	return PremierLeagueMenuStrings;
}

std::vector<std::string> returnOwnTeamsMenu()
{
	std::vector<std::string> ownTeamsMenuStrings
	{
		"> Start simulation",
		"  Back"
	};
	return ownTeamsMenuStrings;
}