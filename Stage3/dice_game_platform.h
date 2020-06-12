
#ifndef dice_game_platform_h
#define dice_game_platform_h
#include <vector>
#include <string>
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
    string getUserName();
protected:
    DiceGamePlatform();
public:
    static DiceGamePlatform* getInstance()
    {
        return singleInstance;
    }
    void startAsession(const Dice& d);
    void registerPhase();
    void registerUser(string name);
    void start(const Dice& dice);
    void gamePhase(const Dice& dice);
    void startSession(const Dice& dice);
    void SessionAcceptUser(int index, IStrategy* s);
    IStrategy* getStrategy(unsigned index);
};
#endif /* dice_game_platform_h */
