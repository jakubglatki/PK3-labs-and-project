#include "stdafx.h"
#include "Sprite.h"

//Sprite
void Sprite::DoDraw(Console &console)
{
	console.DrawTextOnPlayground((short)x, (short)y, DoGetInfo(), GetColor());
}

void Sprite::SetDx(float dx)
{
	this->dx = dx;
}
void Sprite::SetDy(float dy)
{
	this->dy = dy;
}
void Sprite::SetText(std::string text)
{
	this->actionText = text;
}
void Sprite::SetColor(WORD color)
{
	this->color = color;
}

WORD Sprite::GetColor() const
{
	return color;
}
float Sprite::GetXPosition() const
{
	return x;
}
Sprite::Sprite(WORD _color)
{
	this->color = _color;
}
float Sprite::GetYPosition() const
{
	return y;
}
std::string Sprite::DoGetInfo()
{
	return std::string();
}

void Sprite::DoAction(Console &console)
{
	if (actionActualFrame == actionLastFrame)
	{
		Action action = ActionInfo(0);
		int random_number = rand() % 100;
		int newFunctionIndex = 0;
		int sum = action.probability;

		while (random_number > sum)
		{
			action = ActionInfo(++newFunctionIndex);
			sum += action.probability;
		}

		currentActionFunction = action.actionFunction;
		actionLastFrame = action.frameNumber;
		actionText = action.actionText;
		actionActualFrame = 0;
	}

	(this->*currentActionFunction)(console);
	actionActualFrame++;
}