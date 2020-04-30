#pragma once
#ifndef DICE_H
#define DICE_H
#include <cstdlib>

static unsigned int randomNum(int x)
{
	return rand()%x+1;
}

class CDice
{
private:
	unsigned int m_upVal;

public:
	CDice() :m_upVal(0){};
	unsigned rollDice()
	{
		m_upVal = randomNum(6) + 1;
		return m_upVal;
	}
	unsigned getVal()const
	{
		return m_upVal;
	}
	void reset()
	{
		m_upVal = 0;
	}
};


#endif
