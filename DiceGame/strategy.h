#pragma once
#ifndef STRATEGY_H
#define STRATEGY_H

#include "player.h"
#include "game_res.h"


class IGameStrategy
{
protected:
	virtual unsigned calCredit(const Player& player) = 0;
public:
	// WIN for player1 win...
	virtual shared_ptr<GameRes> judge(Player& player1, Player& player2) = 0;
	virtual ~IGameStrategy(){;}
};

class CAddRemaind6:public IGameStrategy
{
public:
	virtual unsigned calCredit(const Player& player) override;
	virtual shared_ptr<GameRes> judge(Player& player1, Player& player2) override;
};

class CMutRemaind6:public IGameStrategy
{
public:
	virtual unsigned calCredit(const Player& player) override;
	virtual shared_ptr<GameRes> judge(Player& player1, Player& player2) override;
};


class CAverage:public IGameStrategy
{
public:
    virtual unsigned calCredit(const Player& player) override;
    virtual shared_ptr<GameRes> judge(Player& player1, Player& player2) override;
};

#endif // !STRATEGY_H

