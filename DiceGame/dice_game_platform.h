#pragma once
#ifndef DICE_GAME_PLATFORM_H
#define DICE_GAME_PLATFORM_H
#include "player.h"
#include "game_table.h"
#include <set>
#include <queue>
#include <memory>
#include <list>

class CDiceGamePlatform
{
private:
	// defined as static for thread security
	static CDiceGamePlatform* singleInstance;
	static const unsigned TableNum; 
	list<shared_ptr<CGameTable>>gameTables;
	set<CPlayer>m_players;
	queue<CPlayer*>onlinePlayers;

	static void initRand();
		
protected:
	CDiceGamePlatform();
public:
	static CDiceGamePlatform* getInstance()
	{
		return singleInstance;
	}
	// ע��ɹ�����CPlayerָ�룬ʧ�ܷ���nullptr
	shared_ptr<CPlayer> regPlayer(string player_name);

	// player��¼
	bool login(const CPlayer& player);

	bool trySeat(CPlayer* player);
	
};


#endif
