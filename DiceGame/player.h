#pragma once
#ifndef PLAYER_H
#define PLAYER_H
#include "dice.h"
#include <vector>
#include <string>
using namespace std;

class CPlayer
{
public:
	enum class ESessionState { OFFLINE, ONLINE, PREPARED, PLAYING };
private:	
	static unsigned undefined_name_num;		//TODO: need to ensure thread security
	static const unsigned DiceNum;
	vector<CDice>m_dices;
	char m_curCommand;
	ESessionState sessionState;
protected:
	string m_name;

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
	CPlayer() : m_dices(DiceNum), m_curCommand(0), sessionState(ESessionState::OFFLINE)
	{
		m_name = "undefined name" + to_string(getUndefinedNum());
		IncUndefinedNum();
	};
	CPlayer(string& _name) :m_dices(DiceNum), m_curCommand(0), sessionState(ESessionState::OFFLINE), m_name(_name) { ; }
	CPlayer(const char *_name) :m_dices(DiceNum), m_curCommand(0), sessionState(ESessionState::OFFLINE), m_name(_name){;}

	string getName()const
	{
		return m_name;
	}

	const vector<CDice>& getDices()const { return m_dices; }

	void initialize() {
		for (auto dice : m_dices)
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

	unsigned rollDice(unsigned round);

	bool operator==(const CPlayer& another_player)const
	{
		return this->m_name == another_player.m_name;
	}

	bool operator<(const CPlayer& another_player)const
	{
		return m_name<another_player.getName();
	}
	
};










#endif




