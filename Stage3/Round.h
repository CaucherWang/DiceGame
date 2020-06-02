#ifndef Round_h
#define Round_h

#include <stdio.h>
#include <vector>
#include <string>
#include "Turn.h"
using namespace std;


class Round{
private:
    unsigned roundIndex;
    unsigned pointsBet; // all points that is bet by players
    vector<Turn*> turns;
    vector<string> winners;
public:
    Round(unsigned roundIndex, vector<shared_ptr<Player>> players);
    void printRoundResult();
    void getCredits(unsigned c){pointsBet += c;}
    void finish();
    vector<Turn*>& getTurns(){
        return turns;
    }
};
#endif /* Round_h */
