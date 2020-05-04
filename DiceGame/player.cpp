#include "player.h"
#include <iostream>
using std::cin;
using std::cout;

const unsigned Player::DiceNum = 2;
unsigned Player::undefined_name_num = 0;


unsigned Player::rollDice(unsigned round) {
    if (round >= 2)
        return 0;
    return dices[round]->rollDice();
}


