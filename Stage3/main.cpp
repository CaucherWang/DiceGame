

#include <iostream>
#include "dice_game_platform.h"
using namespace std;
int main(int argc, const char * argv[]) {
    //register
    auto platform = DiceGamePlatform::getInstance();
    srand(time(nullptr));
    const Dice dice;
    platform->registerPhase();
    platform->gamePhase(dice);
    return 0;
}
