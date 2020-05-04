#pragma once
#ifndef DICE_H
#define DICE_H
#include <cstdlib>

static unsigned int randomNum(int x)
{
	return rand()%x+1;
}

class Dice
{
protected:
	unsigned int upVal;

public:
	Dice() :upVal(0){};
	virtual unsigned rollDice()
	{
		upVal = randomNum(6);
		return upVal;
	}
	unsigned getVal()const
	{
		return upVal;
	}
	void reset()
	{
		upVal = 0;
	}
};

// for test
class TestDice:public Dice
{
	unsigned rolledNum,myNum;
	static unsigned testNum;
	unsigned mockRollDice()const
	{
		return (3+2*rolledNum+4*myNum)%6 +1;
	}
public:
	TestDice():rolledNum(0){++testNum;myNum=testNum;}
	virtual unsigned rollDice() override
	{
		++rolledNum;
		upVal = mockRollDice();
		return upVal;
	}
};

#endif
