#include "Round.h"
Round::Round(unsigned roundIndex, vector<shared_ptr<Player>> players):
roundIndex(roundIndex),winners(){
    pointsBet = 0;
    for(auto player: players){
        turns.push_back(new Turn(player));
        pointsBet++;
    }
}
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
