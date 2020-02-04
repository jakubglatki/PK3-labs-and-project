#include "teamsPL.h"


//based on table from 11.11.2018 (and personal bias)
std::vector<class Table> makeTeams() {
	Table MCI(5, 4, "Manchester City");
	Table LIV(4, 5, "Liverpool FC");
	Table CHE(4, 4, "Chelsea FC");
	Table ARS(4, 3, "Arsenal FC");
	Table TOT(4, 4, "Tottenham Hotspur");
	Table BOU(3, 3, "AFC Bournemouth");
	Table WAT(3, 3, "Watford");
	Table MUN(2, 2, "Manchester United");
	Table EVE(3, 2, "Everton FC");
	Table LEI(2, 3, "Leicester City");
	Table WOL(2, 3, "Wolverhampton");
	Table BHA(2, 2, "Brighton");
	Table WHU(3, 2, "West Ham United");
	Table NEW(1, 3, "Newcastle United");
	Table BUR(2, 1, "Burnley FC");
	Table CRY(1, 2, "Crystal Palace");
	Table SOU(1, 2, "Southampton FC");
	Table CAR(2, 1, "Cardiff City");
	Table HUD(1, 2, "Huddersfield Town");
	Table FUL(2, 1, "Fulham FC");

	std::vector <class Table> PLTables = { MCI, LIV, CHE, ARS, TOT, BOU, WAT, MUN, EVE, LEI, WOL, BHA, WHU, NEW, BUR, CRY, SOU, CAR, HUD, FUL };

	return PLTables;
}