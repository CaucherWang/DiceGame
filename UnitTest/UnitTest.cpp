#include "pch.h"
#include "CppUnitTest.h"
#include "../DiceGame/dice_game_platform.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(DiceGamePlatformTest)
	{
	public:
		
		TEST_METHOD(login)
		{
			auto test_platform = DiceGamePlatform::getInstance();
			Player player_A("A"), player_B("B");
			test_platform->login(player_A);
			test_platform->login(player_B);
			
		}
	};
}
