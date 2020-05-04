#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include <vector>
#include <string>
#include <memory>
using namespace std;

class Player
{
public:
	enum class ESessionState { OFFLINE, ONLINE, PLAYING };
private:	
	static unsigned undefined_name_num;		//TODO: need to ensure thread security
	static const unsigned DiceNum;
	vector<shared_ptr<Dice>>dices;
	ESessionState sessionState;
	void initDice(bool test_flag=false)
	{
		if(test_flag)
		{
			dices.emplace_back(new TestDice);
			dices.emplace_back(new TestDice);
		}
		else
		{
			dices.emplace_back(new Dice);
			dices.emplace_back(new Dice);
		}
	}
protected:
	string name;

	// TODO: thread security ensure 
	unsigned getUndefinedNum()const
	{
		return undefined_name_num;
	}
	static void IncUndefinedNum()
	{
		++undefined_name_num;
	}
public:
	Player() : sessionState(ESessionState::OFFLINE)
	{
		initDice();
		name = "undefined name" + to_string(getUndefinedNum());
		IncUndefinedNum();
	};
	Player(string& _name, bool test_flag=false) :sessionState(ESessionState::OFFLINE), name(_name)
	{
		initDice(test_flag);
	}
	Player(const char *_name, bool test_flag=false) :sessionState(ESessionState::OFFLINE), name(_name)
	{
		initDice(test_flag);
	}

	string getName()const
	{
		return name;
	}

	const vector<shared_ptr<Dice>>& getDices()const { return dices; }

	void initialize() {
		for (auto dice : dices)
			dice.reset();
	}

	ESessionState signUp()
	{
		if(sessionState == ESessionState::OFFLINE || sessionState == ESessionState::ONLINE)
		{
			sessionState = ESessionState::ONLINE;
			return ESessionState::ONLINE;
		}
		return sessionState;
	}

	ESessionState getState()const
	{
		return sessionState;
	}

	unsigned rollDice(unsigned round);

	bool operator==(const Player& another_player)const
	{
		return this->name == another_player.name;
	}

	bool operator<(const Player& another_player)const
	{
		return name<another_player.getName();
	}
	
};


#endif




