#pragma warning(disable:26444)
#include "dice_game_platform.h"
#include <ctime>

CDiceGamePlatform* CDiceGamePlatform::singleInstance = new CDiceGamePlatform();
const unsigned CDiceGamePlatform::TableNum = 10;

CDiceGamePlatform::CDiceGamePlatform()
{
	for(unsigned i=0;i<TableNum;++i)
		gameTables.push_back(make_shared<CGameTable>());
	regPlayer("A"); regPlayer("B");
	initRand();
}

void CDiceGamePlatform::initRand()
{
	srand(time(nullptr));
}

shared_ptr<CPlayer> CDiceGamePlatform::regPlayer(string player_name)
{
	shared_ptr<CPlayer>new_player(new CPlayer(player_name));
	auto res = m_players.insert(*new_player);
	if (res.second)
		return new_player;
	return nullptr;
}

bool CDiceGamePlatform::login(const CPlayer& player)
{
	auto const_player_iter = m_players.find(player);
	if(const_player_iter == m_players.end())
		return false;
	auto player_v = const_cast<CPlayer*>(&(*const_player_iter));
	auto session_state = player_v->signUp();
	if(session_state == CPlayer::ESessionState::ONLINE)
	{
		bool seat_res = trySeat(player_v);
		if(!seat_res)
			onlinePlayers.push(player_v);
	}
	return false;
}

bool CDiceGamePlatform::trySeat(CPlayer* player)
{
	for(auto game_table=gameTables.begin();game_table!=gameTables.end();++game_table)
		if((*game_table)->joinTable(player))
			return true;
	return false;
}




