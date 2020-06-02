
#ifndef dice_game_platform_h
#define dice_game_platform_h

#include <stdio.h>
#include <vector>
#include <list>
#include "User.h"
#include "Dice.h"
#include "GameSession.h"
#include "IStrategy.h"
class DiceGamePlatform{
private:
    static DiceGamePlatform* singleInstance;
    vector<shared_ptr<User>> users;
    list<shared_ptr<GameSession>> gameSessions;
    static const unsigned sessionNum = 10;
    bool isEnd;
protected:
    DiceGamePlatform();
public:
    static DiceGamePlatform* getInstance()
    {
        return singleInstance;
    }
    void registerPhase();
    void registerUser();
    void start(const Dice& dice);
    void gamePhase(const Dice& dice);
    void startSession(const Dice& dice);
    IStrategy* getStrategy(unsigned index);
};
#endif /* dice_game_platform_h */
