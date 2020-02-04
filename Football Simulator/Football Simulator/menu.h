#pragma once
#include <vector>
#include <string>
#include <Windows.h>
#include <iostream>

enum menuType {
	Main, PremierLeague, OwnTeams
};

class Menu
{
private:
	std::vector<std::string> options;
	int index = 0;
	menuType type;
public:
	Menu() {};
	Menu(std::vector<std::string> options)
	{
		this->options = options;
		index = 0;
	}

	void setVector(std::vector<std::string>);
	void setIndex(int);
	void setMenuType(menuType type);

	std::vector<std::string> getVector() const;
	int getIndex() const;
	menuType getMenuType() const;

	void moveArrow();
	void show() const;
	~Menu() {};
};
