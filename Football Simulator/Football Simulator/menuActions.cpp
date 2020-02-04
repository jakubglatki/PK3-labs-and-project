#include "menuActions.h"

void clearScreen()
{
	system("cls");
}

bool isEscape(const KEY_EVENT_RECORD key)
{
	bool escapeClicked = true;
	if (key.wVirtualKeyCode == VK_ESCAPE)
	{
		escapeClicked = true;
	}
	else
	{
		escapeClicked = false;
	}
	return escapeClicked;
}

bool getConChar(KEY_EVENT_RECORD& krec)
{
	DWORD cc;
	INPUT_RECORD irec;
	HANDLE h = GetStdHandle(STD_INPUT_HANDLE);

	if (h == NULL)
	{
		return false; // console not found
	}

	for (; ;)
	{
		ReadConsoleInput(h, &irec, 1, &cc);
		if (irec.EventType == KEY_EVENT
			&& ((KEY_EVENT_RECORD&)irec.Event).bKeyDown
			)
		{
			krec = (KEY_EVENT_RECORD&)irec.Event;
			return true;
		}
	}
	return false;
}

bool isFinished(const menuType currentType, const Menu menu)
{
	bool isFinished = false;
	if (currentType == PremierLeague)
	{
		if (menu.getIndex() == 0)
		{
			isFinished = true;
		}
	}
	else
		if (currentType == OwnTeams)
		{
			if (menu.getIndex() == 0)
			{
				isFinished = true;
			}
		}

	return isFinished;
}

void mainMenuAction(Menu & menu, KEY_EVENT_RECORD & key)
{
	switch (menu.getIndex())
	{
	case 0:
		menu.setVector(returnPremierLeagueMenu());
		menu.setMenuType(PremierLeague);
		break;
	case 1:
		menu.setVector(returnOwnTeamsMenu());
		menu.setMenuType(OwnTeams);
		break;
	case 2:
		key.wVirtualKeyCode = VK_ESCAPE;
		break;
	default:
		break;
	}
}

void PremierLeagueMenuAction(Menu & menu)
{
	std::vector<Table> PLteams = makeTeams();
	switch (menu.getIndex())
	{
	case 0:
		clearScreen();
		PLteams = makeSchedule(&PLteams);
		drawTable(&PLteams);
		break;
	case 1:
		menu.setVector(returnMainMenu());
		menu.setMenuType(Main);
		break;
	default:
		break;
	}
}

void OwnTeamsMenuAction(Menu & menu)
{
	std::vector<Table> OwnTeams = userTeams(menu);
	switch (menu.getIndex())
	{
	case 0:
		clearScreen();
		OwnTeams = makeSchedule(&OwnTeams);
		drawTable(&OwnTeams);
		break;
	case 1:
		menu.setVector(returnMainMenu());
		menu.setMenuType(Main);
		break;
	default:
		break;
	}
}

void switchMenu(menuType & currentType, Menu & menu, KEY_EVENT_RECORD & key)
{
	switch (currentType)
	{
	case Main:
		mainMenuAction(menu, key);
		break;
	case PremierLeague:
		PremierLeagueMenuAction(menu);
		break;
	case OwnTeams:
		OwnTeamsMenuAction(menu);
		break;
	default:
		break;
	}
}

void chooseAction(Menu & menu, KEY_EVENT_RECORD & key)
{
	do
	{
		clearScreen();
		menu.show();
		getConChar(key);
		menu.moveArrow();

	} while (key.wVirtualKeyCode != VK_RETURN && key.wVirtualKeyCode != VK_SPACE && key.wVirtualKeyCode != VK_ESCAPE);
}

void runMenu(Menu & menu)
{
	KEY_EVENT_RECORD key = { 0, 0, 0, 0, };
	menu.setVector(returnMainMenu());

	do
	{
		menu.setIndex(0);
		menuType currentType = menu.getMenuType();

		chooseAction(menu, key);


		switchMenu(currentType, menu, key);

		if (isFinished(currentType, menu))
			break;

	} while (!isEscape(key));
}
