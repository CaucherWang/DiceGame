//
//  Round.cpp
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#include "Round.h"
Round::Round(unsigned roundIndex, vector<shared_ptr<Player>> players):
roundIndex(roundIndex),winners(){
    pointsBet = 0;
    for(auto player: players){
        turns.push_back(new Turn(player));
        pointsBet++;
    }
}
/*第 1 轮：玩家 alice, bob 瓜分 15 点积分；
 第 2 轮：玩家 alice, carl 瓜分 12 点积分；
 当前各玩家积分余额： alice 7, bob 1, carl 2*/
void Round::printRoundResult(){
    if(!winners.empty()){
        cout << "Round "<<roundIndex<<": Player ";
        for (int i = 0; i < winners.size() - 1; i++) {
            cout<<winners.at(i)<<", ";
        }
        cout<<winners.back()<<" divided up "<<pointsBet<<" points;"<<endl;
    }
}


void Round::finish(){
    //divide credits
    unsigned winNum = 0;
    unsigned maxPoints = 0;
    unsigned p;
    for (auto turn:turns) {
        p = turn->getPoints();
        if (p > maxPoints) {
            maxPoints = p;
        }
    }
    for (auto turn:turns) {
        p = turn->getPoints();
        if (p == maxPoints) {
            winNum++;
            winners.push_back(turn->getName());
        }
    }
    for (auto turn:turns) {
        p = turn->getPoints();
        if (p == maxPoints) {
            turn->getPlayer()->changeCredits(maxPoints/winNum, WINGAME);
        }
    }
}
