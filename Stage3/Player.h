#ifndef Player_h
#define Player_h

#include "IStrategy.h"
#include "User.h"
#include "../Final/Project1/IUpdatePoints.h"

class Player:public IUpdatePoints{
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
	virtual void updatePoints(double credit, event name) override{changeCredits(-credit,name);}
};
#endif /* Player_h */
