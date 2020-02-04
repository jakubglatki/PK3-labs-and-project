#include "menu.h"
void Menu::setVector(std::vector<std::string> options)
{
	this->options = options;
}

void Menu::setIndex(int index)
{
	this->index = index;
}

void Menu::setMenuType(menuType type)
{
	this->type = type;
}

std::vector<std::string> Menu::getVector() const
{
	return options;
}

int Menu::getIndex() const
{
	return index;
}

menuType Menu::getMenuType() const
{
	return type;
}

void Menu::moveArrow()
{
	if (GetAsyncKeyState(VK_UP))
	{
		if (index != 0)
		{
			options.at(index).replace(0, 1, " ");
			index = index - 1;
			options.at(index).replace(0, 1, ">");
		}
	}
	else
		if (GetAsyncKeyState(VK_DOWN))
		{
			if (index != options.size() - 1)
			{
				options.at(index).replace(0, 1, " ");
				index = index + 1;
				options.at(index).replace(0, 1, ">");
			}
		}
}

void Menu::show() const
{
	
	for (auto i = options.begin(); i != options.end(); ++i)
	{
		std::cout << *i << std::endl;
	}
}