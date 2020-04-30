#include "dice_game_platform.h"
#include <memory>
#include <vector>
int main()
{
	auto platform = CDiceGamePlatform::getInstance();
	CPlayer player_A("A"), player_B("B");
	platform->login(player_A);
	platform->login(player_B);
}