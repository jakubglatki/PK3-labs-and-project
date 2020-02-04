#pragma once
#include "Console.h"

class Sprite
{
public:
	float x, y;
	float dx = 0.0f, dy = 0.0f;
	WORD color = 0;
	int actionActualFrame = 0;
	int actionLastFrame = 1;
	std::string actionText;
	typedef void (Sprite::*ActionFunction)(Console&);
	struct Action
	{
		int probability;
		std::string actionText;
		int frameNumber;
		ActionFunction actionFunction;
	};
	ActionFunction currentActionFunction = &Sprite::ActionThinking;
	void SetDx(float dx);
	void SetDy(float dy);
	void SetText(std::string text);
	void SetColor(WORD color);
	float GetXPosition() const;
	float GetYPosition() const;
	virtual void DoDraw(Console &);
	virtual void DoAction(Console &);
	virtual std::string DoGetInfo();
	virtual Action ActionInfo(int index) = 0;
	virtual void ActionThinking(Console &console) = 0;
	virtual void ActionMoving(Console &console) = 0;
	virtual void ActionSpecial(Console &console) = 0;
	virtual void ActionSleeping(Console &console) = 0;
	WORD GetColor() const;
	Sprite(WORD);
};
