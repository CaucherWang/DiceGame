//
//  Player.cpp
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#include "Player.h"

void Player::changeCredits(int points, event e){
    user->changeCredits(points, e);
}

string Player::getName(){
    return user->getName();
}

unsigned Player::calPoints(unsigned int p1, unsigned int p2){
    return strategy->calculatePoints(p1, p2);
}

