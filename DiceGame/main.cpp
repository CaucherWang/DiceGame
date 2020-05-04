#include "dice_game_platform.h"

int main()
{
	auto platform = DiceGamePlatform::getInstance();
	Player player_A("A"), player_B("B");
	platform->login(player_A);
	platform->login(player_B);
}