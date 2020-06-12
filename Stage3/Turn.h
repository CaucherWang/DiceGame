#pragma once

#ifndef Turn_h
#define Turn_h

#include <vector>
#include "Player.h"

class Round;

class Turn{
private:
    unsigned move;
    shared_ptr<Player> player;
    unsigned points;
	Round *round;
	vector<IUpdatePoints*>pointsUpdateListeners;
    
public:
	Turn(shared_ptr<Player>& p, Round* r):player(p){round=r;pointsUpdateListeners.push_back((IUpdatePoints*)(r));pointsUpdateListeners.push_back(&(*p));notify(1,BETTING);}
    string getName(){return player->getName();}
    unsigned setPoints(unsigned p1, unsigned p2);
    unsigned modifyPoints();
    int getCredits(){return player->getCredits();}
    unsigned getPoints(){return points;}
    shared_ptr<Player> getPlayer(){return player;}
    void printCreditRecords(){player->printCreditRecords();}
	void notify(double credit,event name)
    {
	    for(auto listener:pointsUpdateListeners)
            listener->updatePoints(credit,name);
    }
    unsigned modify_n(int p);
};
#endif /* Turn_h */
