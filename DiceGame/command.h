#pragma once
#ifndef COMMAND_H
#define COMMAND_H
#include "game_table.h"
#include <iostream>


// Command类对象将直接操纵GameTable中私有成员
class Command
{
protected:
	GameTable& game_table;
public:
	Command(GameTable& table):game_table(table){;}
	virtual void execute()=0;
};

class StartCommand:public Command
{
public:
	virtual void execute() override;
	StartCommand(GameTable& table):Command(table){;}
};

class RollCommand:public Command
{
	void rollDices(unsigned *res_1, unsigned *res_2);
	bool showResult(unsigned res_1,unsigned res_2,unsigned round);
	void dealFinal();
public:
	virtual void execute() override;
	RollCommand(GameTable& table):Command(table){;}
};

class QuitCommand:public Command
{
	void showHisResult()const;
	void refreshTable();
public:
	virtual void execute() override;
	QuitCommand(GameTable& table):Command(table){;}
};

class CommandFactory
{
protected:
	GameTable& game_table;
	shared_ptr<StartCommand>start_command;
	shared_ptr<RollCommand>roll_command;
	shared_ptr<QuitCommand>quit_command;
	shared_ptr<Command> findCommand(char input);
	bool duringRound;
public:
	CommandFactory(GameTable& table):game_table(table)
	{
		start_command=make_shared<StartCommand>(table);
		roll_command=make_shared<RollCommand>(table);
		quit_command=make_shared<QuitCommand>(table);
		duringRound=false;
	}
	virtual shared_ptr<Command> getCommand();
};

class TestCommandFactory:public CommandFactory
{
	unsigned pos;
	vector<char>commandSeries;
public:
	TestCommandFactory(GameTable &table):CommandFactory(table)
	{
		commandSeries={'s','r','r','s','r','r','s','s','q'};
	}
	shared_ptr<Command> getCommand() override;
};

#endif 

