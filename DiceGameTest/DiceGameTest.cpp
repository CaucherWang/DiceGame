#include "pch.h"
#include "CppUnitTest.h"
#include "../DiceGame/dice_game_platform.h"
#include <iostream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace DiceGameTest
{
	TEST_CLASS(DiceGamePlatformTest)
	{
	public:
		
		TEST_METHOD(regPlayerTest)
		{
			Logger::WriteMessage("Test DiceGamePlatform");
			string test_player_A("A"),test_player_B("A");
			auto test_platform = DiceGamePlatform::getInstance();
			auto res_A=test_platform->regPlayer(test_player_A);
			auto res_B=test_platform->regPlayer(test_player_B);
			Assert::IsTrue(res_A==nullptr);
			Assert::IsTrue(res_B==nullptr);
			Logger::WriteMessage("duplicate register refused.");

			Assert::IsTrue(test_platform->hasRegistered("A"));
			Assert::IsTrue(test_platform->hasRegistered("B"));
			Logger::WriteMessage("player A, B has been pre-registered.");

			string test_player_C("C");
			auto res_C=test_platform->regPlayer(test_player_C);
			Assert::IsFalse(res_C==nullptr);
			Logger::WriteMessage("new player is able to register.");
		}
		
		TEST_METHOD(programTest)
		{
			auto platform = DiceGamePlatform::getInstance();
			Logger::WriteMessage("Test Login");
			Player test_player_D("D");			
			auto game_table1 = platform->login(test_player_D);
			Assert::IsTrue(game_table1==nullptr);
			Logger::WriteMessage("unregistered player is not allowed to login.");
		
			Player test_player_A("A",true);
			auto game_table=platform->login(test_player_A,0);
			Assert::IsFalse(game_table==nullptr);
			Assert::IsTrue(platform->checkPlayerState(test_player_A)==Player::ESessionState::ONLINE);
			Logger::WriteMessage("registered player is able to login.");
		
			Player test_player_B("B",true);
			auto same_game_table = platform->login("B",0);
			Assert::IsFalse(same_game_table==nullptr);
			Assert::IsTrue(platform->checkPlayerState(test_player_B)==Player::ESessionState::ONLINE);
		
			Assert::IsTrue(game_table==same_game_table);
			Logger::WriteMessage("continuous players are in the same table.");
			vector<GameRes>& his_res = GameTable::last_game_his_res;
			Assert::AreEqual(his_res[0].getPlayer1Res(),0u);
			Assert::AreEqual(his_res[0].getPlayer2Res(),4u);
			Assert::IsTrue(his_res[0].getRes()== GameRes::EGameResult::LOSE);
			Assert::AreEqual(his_res[1].getPlayer1Res(),4u);
			Assert::AreEqual(his_res[1].getPlayer2Res(),2u);
			Assert::IsTrue(his_res[1].getRes()==GameRes::EGameResult::WIN);
			Logger::WriteMessage("strategy 1 test success.");
		
			string name_player_C("C");
			auto res_C=platform->regPlayer(name_player_C);
			Assert::IsFalse(res_C==nullptr);
		
			string name_player_D("D");
			auto res_D=platform->regPlayer(name_player_D);
			Assert::IsFalse(res_D==nullptr);
			auto game_table_2=platform->login(*res_C,1);
			auto same_game_table_2=platform->login(*res_D,1);
			vector<GameRes>& his_res_2=GameTable::last_game_his_res;
			Assert::IsTrue(game_table_2==same_game_table_2);
			Assert::AreEqual(his_res_2[0].getPlayer1Res(),0u);
			Assert::AreEqual(his_res_2[0].getPlayer2Res(),0u);
			Assert::IsTrue(his_res_2[0].getRes()==GameRes::EGameResult::DRAW);
			Assert::AreEqual(his_res_2[1].getPlayer1Res(),0u);
			Assert::AreEqual(his_res_2[1].getPlayer2Res(),2u);
			Assert::IsTrue(his_res_2[1].getRes()== GameRes::EGameResult::LOSE);
			Logger::WriteMessage("strategy 2 test success.");			
		}

	};
}
