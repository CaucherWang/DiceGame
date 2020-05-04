#include "game_table.h"
#include "message_print.h"
#include "command.h"
#define TEST

vector<GameRes> GameTable::last_game_his_res;

//TODO:thread security
//hint:如果游戏参与进一步复杂，应考虑继承GameTable，形成多态，目前暂无必要
bool GameTable::joinTable(Player* player,int strategy)
{
	switch (table_state)
	{
	case ETableState::CLOSED:
		player1 = player;
		table_state = ETableState::WAITING;
		return true;
	case ETableState::WAITING:
		player2 = player;
		table_state = ETableState::PLAYING;
		startGame(strategy);
		return true;
	case ETableState::PLAYING:
	default:
		return false;
	}
}

void GameTable::startGame(int strategy)
{
	CMessagePrint::printWelcome();
	setStrategy(strategy);
	auto command_factory=new CommandFactory(*this);
#ifdef TEST
	command_factory=new TestCommandFactory(*this);
#endif
	shared_ptr<Command>command;
	while (table_state!= ETableState::CLOSED)
	{
		command = command_factory->getCommand();
		command->execute();
	}
}

void GameTable::setStrategy(int strategy)
{
	if(strategy<0)
		strategy = inputStrategy();
	switch (strategy)
	{
	case 0:
		game_strategy = new CAddRemaind6;
		return;
	case 1:
	default:
		game_strategy = new CMutRemaind6;
		return;
	}
}

unsigned GameTable::inputStrategy() const
{
	CMessagePrint::printStrategy();
	unsigned res;
	cin>>res;
	return res;
}


