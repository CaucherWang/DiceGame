#pragma once
#ifndef GAME_RES_H
#define GAME_RES_H

class GameRes
{
public:
	enum class EGameResult{ WIN,LOSE,DRAW };
private:
	EGameResult m_result;
	unsigned res_player1,res_player2;
public:
	GameRes& setRes(unsigned res1, unsigned res2)
	{
		res_player1=res1;
		res_player2=res2;
		if(res1>res2)
			m_result= EGameResult::WIN;
		else  if(res1<res2)
			m_result= EGameResult::LOSE;
		else m_result= EGameResult::DRAW;
		return *this;
	}

	EGameResult getRes()const
	{
		return m_result;
	}

	unsigned getPlayer1Res()const
	{
		return res_player1;
	}

	unsigned getPlayer2Res()const
	{
		return res_player2;
	}
};

#endif // !GAME_RES_H

