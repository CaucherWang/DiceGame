#pragma once
#ifndef DICE_GAME_PLATFORM_H
#define DICE_GAME_PLATFORM_H
#include "player.h"
#include <set>
#include <list>

class CDiceGamePlatform
{
private:
	// defined as static for thread security
	static CDiceGamePlatform* singleInstance;
	set<CPlayer&>m_players;
	
	
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
	
};


#endif
