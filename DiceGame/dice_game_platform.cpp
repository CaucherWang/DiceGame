#pragma warning(disable:26444)
#include "dice_game_platform.h"
#include <ctime>
#define TEST

DiceGamePlatform* DiceGamePlatform::singleInstance = new DiceGamePlatform();
const unsigned DiceGamePlatform::TableNum = 10;

DiceGamePlatform::DiceGamePlatform()
{
	for(unsigned i=0;i<TableNum;++i)
		gameTables.push_back(make_shared<GameTable>());
	regPlayer("A"); regPlayer("B");
	initRand();
}

void DiceGamePlatform::initRand()
{
	srand(time(nullptr));
}

shared_ptr<Player> DiceGamePlatform::regPlayer(string player_name)
{
#ifndef TEST
	shared_ptr<Player>new_player(new Player(player_name));
#endif
#ifdef TEST
	shared_ptr<Player>new_player(new Player(player_name,true));
#endif
	
	auto res = players.insert(*new_player);
	if (res.second)
		return new_player;
	return nullptr;
}

shared_ptr<GameTable> DiceGamePlatform::login(const Player& player,int strategy)
{
	auto const_player_iter = players.find(player);
	if(const_player_iter == players.end())
		return nullptr;
	auto player_v = const_cast<Player*>(&(*const_player_iter));
	auto session_state = player_v->signUp();
	if(session_state == Player::ESessionState::ONLINE)
	{
		auto seat_res = trySeat(player_v, strategy);
		if(seat_res==gameTables.end())
		{
			onlinePlayers.push(player_v);
			return nullptr;
		}
		return *seat_res;
	}
	return nullptr;
}

list<shared_ptr<GameTable>>::iterator DiceGamePlatform::trySeat(Player* player, int strategy)
{
	for(auto game_table=gameTables.begin();game_table!=gameTables.end();++game_table)
		if((*game_table)->joinTable(player,strategy))
			return game_table;
	return gameTables.end();
}




