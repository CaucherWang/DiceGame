//
//  Turn.h
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#ifndef Turn_h
#define Turn_h

#include <stdio.h>
#include "Player.h"
class Turn{
private:
    unsigned move;
    shared_ptr<Player> player;
    unsigned points;
    
public:
    Turn(shared_ptr<Player> p):player(p){}
    string getName(){return player->getName();}
    unsigned setPoints(unsigned p1, unsigned p2);
    unsigned modifyPoints();
    int getCredits(){return player->getCredits();}
    unsigned getPoints(){return points;}
    shared_ptr<Player> getPlayer(){return player;}
    void printCreditRecords(){player->printCreditRecords();}
};
#endif /* Turn_h */
