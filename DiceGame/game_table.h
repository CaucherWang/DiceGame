#pragma once
#ifndef GAME_TABLE_H
#define GAME_TABLE_H
#include "player.h"
#include "strategy.h"
#include "game_res.h"

class GameTable
{
	friend class StartCommand;
	friend class RollCommand;
	friend class QuitCommand;
	friend class CommandFactory;
public:
	enum class ETableState{CLOSED,WAITING,PLAYING};
	static vector<GameRes>last_game_his_res;	//only for test
private:
	Player*player1, *player2;
	ETableState table_state;
	unsigned game_round;	// indicate how many times dices have been rolled during a round
	unsigned round;
	vector<GameRes>history_result;
	IGameStrategy *game_strategy;

protected:
	unsigned inputStrategy() const;
	void setStrategy(int strategy);

public:
	GameTable() {player1 = player2 = nullptr; table_state = ETableState::CLOSED; game_round=0; round=0; game_strategy=nullptr;}
	virtual ~GameTable()
	{
		delete game_strategy;
	}
	bool joinTable(Player *player, int strategy=-1);

	void startGame(int strategy=-1);

	// for test
	const vector<GameRes>& getHisRes()const
	{
		return history_result;
	}
};

#endif // !GAME_TABLE_H

