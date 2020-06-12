#pragma once
#ifndef Round_h
#define Round_h
#include <vector>
#include <string>
#include "Turn.h"
#include "../Final/Project1/IUpdatePoints.h"
using namespace std;


class Round:public IUpdatePoints{
private:
    unsigned roundIndex;
    unsigned pointsBet; // all points that is bet by players
    vector<Turn*> turns;
    vector<string> winners;
public:
    Round(unsigned roundIndex, vector<shared_ptr<Player>> players);
    void printRoundResult();
    void finish();
    vector<Turn*>& getTurns(){
        return turns;
    }
	virtual void updatePoints(double credit, event name=WINGAME) override
    {
	    pointsBet += credit;
    }
};
#endif /* Round_h */
