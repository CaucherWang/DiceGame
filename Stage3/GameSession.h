#ifndef GameSession_h
#define GameSession_h

#include <stdio.h>
#include <vector>
#include <list>
#include "Dice.h"
#include "User.h"
#include "Player.h"
#include "IStrategy.h"
#include "Round.h"
class GameSession{
private:
    vector<shared_ptr<Player>> players;
    vector<shared_ptr<Round>> rounds;
    const Dice& dice;
    bool isEnd;
public:
    GameSession(const Dice& dice):players(), dice(dice), rounds(), isEnd(false){}
    void accept(shared_ptr<User> user, IStrategy* strategy);
    bool isGameEnd(){return isEnd;}
    void play();
    shared_ptr<Round> startRound(unsigned index);
    void printRoundResults();
    void printCurrentCredits();
    unsigned getPlayerNum(){return players.size();}
    unsigned playMove(Turn* turn, unsigned move);
    void removePlayer();
};
#endif /* GameSession_h */
