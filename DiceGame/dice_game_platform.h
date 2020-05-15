#pragma once
#ifndef DICE_GAME_PLATFORM_H
#define DICE_GAME_PLATFORM_H
#include "game_table.h"
#include <set>
#include <queue>
#include <list>

class DiceGamePlatform
{
private:
	// defined as static for thread security
	static DiceGamePlatform* singleInstance;
	static const unsigned TableNum; 
	list<shared_ptr<GameTable>>gameTables;
	set<Player>players;
	queue<Player*>onlinePlayers;

	static void initRand();
		
protected:
	DiceGamePlatform();
public:
	static DiceGamePlatform* getInstance()
	{
		return singleInstance;
	}
	// ×¢²á³É¹¦·µ»ØCPlayerÖ¸Õë£¬Ê§°Ü·µ»Ønullptr
	shared_ptr<Player> regPlayer(string player_name);

	// for test
	bool hasRegistered(string player_name)const
	{
		return players.find(player_name)!=players.end();
	}

	Player::ESessionState checkPlayerState(const Player& player)const
	{
		auto player_iter=players.find(player);
		if(player_iter==players.end())
			return Player::ESessionState::OFFLINE;
		auto player_v = const_cast<Player*>(&(*player_iter));
		return player_v->getState();
	}

	// playerµÇÂ¼
	shared_ptr<GameTable> login(const Player& player, int strategy=-1);

	list<shared_ptr<GameTable>>::iterator trySeat(Player* player, int strategy=-1);
	
};


#endif
