#ifndef Player_h
#define Player_h

#include <stdio.h>
#include "IStrategy.h"
#include "User.h"
class Player{
    shared_ptr<User> user;
    IStrategy* strategy;
public:
    Player(shared_ptr<User> user, IStrategy* strategy):
    user(user),strategy(strategy){}
    void changeCredits(int points, event e);
    int getCredits(){return user->getCredits();}
    string getName();
    unsigned calPoints(unsigned p1, unsigned p2);
    void printCreditRecords(){user->printCreditRecords();}
};
#endif /* Player_h */
