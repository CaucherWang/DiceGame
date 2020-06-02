

#include <iostream>
#include "dice_game_platform.h"
using namespace std;
int main(int argc, const char * argv[]) {
    auto platform = DiceGamePlatform::getInstance();
    srand(time(nullptr));
    const Dice dice;
    platform->start(dice);
    return 0;
}
