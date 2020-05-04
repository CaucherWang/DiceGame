#include "command.h"
#include "message_print.h"
#define TEST

void StartCommand::execute()
{
	game_table.player1->initialize();
	game_table.player2->initialize();
}

void RollCommand::rollDices(unsigned* res_1, unsigned* res_2)
{
	*res_1=game_table.player1->rollDice(game_table.game_round);
	*res_2=game_table.player2->rollDice(game_table.game_round);	
	++game_table.game_round;
}

bool RollCommand::showResult(unsigned res_1, unsigned res_2, unsigned round)
{
	CMessagePrint::printDiceRes(game_table.player1->getName(),game_table.player2->getName(),res_1,res_2);
	if(round>=2)
	{
		dealFinal();
		return true;
	}
	return false;
}

void RollCommand::dealFinal()
{
	auto res = game_table.game_strategy->judge(*(game_table.player1),*(game_table.player2));
	game_table.history_result.push_back(*res);
	CMessagePrint::printRes(*res,game_table.player1->getName(),game_table.player2->getName());
	game_table.game_round=0;	
}

void RollCommand::execute()
{
	unsigned res_1=0,res_2=0;
	rollDices(&res_1,&res_2);
	showResult(res_1,res_2,game_table.game_round);
}

void QuitCommand::showHisResult() const
{
	if(!game_table.history_result.empty())
		CMessagePrint::printHisRes(game_table.history_result,game_table.player1->getName(),game_table.player2->getName());
}

void QuitCommand::refreshTable()
{
#ifdef TEST
	GameTable::last_game_his_res.clear();
	copy(game_table.getHisRes().begin(),game_table.getHisRes().end(),back_insert_iterator<vector<GameRes>>(GameTable::last_game_his_res));
#endif
	game_table.player1=game_table.player2=nullptr;
	delete game_table.game_strategy;
	game_table.game_strategy = nullptr;
	game_table.table_state= GameTable::ETableState::CLOSED;
	game_table.history_result.clear();
	game_table.round=0;
	game_table.game_round = 0;	
}

void QuitCommand::execute()
{
	game_table.table_state= GameTable::ETableState::CLOSED;
	showHisResult();
	refreshTable();	
}

shared_ptr<Command> CommandFactory::getCommand()
{
	char input;
	if(!duringRound)
		CMessagePrint::printRoundCommand();
	else
		CMessagePrint::printCommand();
	while(cin>>input)
	{
		auto res = findCommand(input);
		if(res)
			return res;		
		cin.clear();
	}
	exit(-1);
}

shared_ptr<Command> CommandFactory::findCommand(char input)
{
	switch (input)
	{
	case 's':
		if(duringRound)
			break;
		duringRound=true;
		return start_command;
	case 'r':
		if(!duringRound || (duringRound && game_table.game_round>1))
			break;
		if(game_table.game_round)
			duringRound=false;
		return roll_command;
	case 'q':
		duringRound=false;
		return quit_command;
	default:
		CMessagePrint::printErrInput(input);
	}
	return nullptr;
}

shared_ptr<Command> TestCommandFactory::getCommand()
{
	if(!duringRound)
		CMessagePrint::printRoundCommand();
	else
		CMessagePrint::printCommand();
	while(pos<commandSeries.size())
	{
		auto res=findCommand(commandSeries[pos++]);
		if(res)
			return res;
	}
	exit(-1);
}

