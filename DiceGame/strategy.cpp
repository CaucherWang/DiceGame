#include "strategy.h"

shared_ptr<GameRes> CAddRemaind6::judge(Player& player1, Player& player2)
{
	unsigned res_player1 = calCredit(player1), res_player2 = calCredit(player2);
	shared_ptr<GameRes>res(new GameRes);
	res->setRes(res_player1,res_player2);
	return res;
}

shared_ptr<GameRes> CMutRemaind6::judge(Player& player1, Player& player2)
{
	unsigned res_player1 = calCredit(player1), res_player2 = calCredit(player2);
	shared_ptr<GameRes>res(new GameRes);
	res->setRes(res_player1,res_player2);
	return res;
}

unsigned CAddRemaind6::calCredit(const Player& player)
{
	unsigned sum = 0;
	vector<shared_ptr<Dice>>dices = player.getDices();
	for (auto dice : dices)
		sum += dice->getVal();
	return sum % 6;
}

unsigned CMutRemaind6::calCredit(const Player& player)
{
	unsigned res = 1;
	vector<shared_ptr<Dice>>dices = player.getDices();
	for (auto dice : dices)
		res *= dice->getVal();
	return res % 6;
}


unsigned CAverage::calCredit(const Player &player)
{
    unsigned res = 0;
    vector<shared_ptr<Dice>>dices = player.getDices();
    for (auto dice:dices) {
        res += dice->getVal();
    }
    return res / dices.size();
}

shared_ptr<GameRes> CAverage::judge(Player &player1, Player &player2)
{
}

shared_ptr<GameRes> CMutRemaind6::judge(Player& player1, Player& player2)
{
    unsigned res_player1 = calCredit(player1), res_player2 = calCredit(player2);
    shared_ptr<GameRes>res(new GameRes);
    res->setRes(res_player1,res_player2);
    return res;
}
