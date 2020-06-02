//
//  dice_game_platform.cpp
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#include "dice_game_platform.h"
#include <iostream>
using namespace std;
DiceGamePlatform* DiceGamePlatform::singleInstance = new DiceGamePlatform();
//const unsigned DiceGamePlatform::sessionNum = 10;

DiceGamePlatform::DiceGamePlatform()
{
}

void DiceGamePlatform::registerPhase(){
    unsigned choice = 1;
    while (choice != 2) {
        cout<<"Please Choose: 1. Register a new account，2. End registration. "<<endl;
        cin>>choice;
        if (choice == 1) {
            registerUser();
        }
    }
}

void DiceGamePlatform::registerUser(){
    string name;
    cout<<"Input your user name: ";
    cin>>name;
    users.push_back(make_shared<User>(name));
    users.back()->changeCredits(5, REGISTER);
}

void DiceGamePlatform::gamePhase(const Dice& dice){
    //请选择 1.开始一盘新游戏，2. 结束
    unsigned choice = 1;
    while(choice != 2){
        cout<<"Please Choose: 1.Start a new game，2. Quit"<<endl;
        cin>>choice;
        if(choice == 1){
            startSession(dice);
        }
    }
}

IStrategy* DiceGamePlatform::getStrategy(unsigned int index){
    IStrategy* newStrategy = nullptr;
    switch (index) {
        case 1:
            newStrategy = new CAddRemaind6();
            break;
        case 2:
            newStrategy = new CMutRemaind6();
            break;
        case 3:
            newStrategy = new CAverage();
            break;
        default:
            assert(newStrategy == nullptr);
            break;
    }
    return newStrategy;
}

void DiceGamePlatform::startSession(const Dice& dice){
    gameSessions.push_back(make_shared<GameSession>(dice));
    unsigned choice;
    unsigned playerNum = 0;
    for(auto user: users) {
        if (user->hasOneCredit()) {
            cout << user->getName()<<" Please choose: 1. Join the game, 2. Stay put. "<<endl;
            cin>>choice;
            if (choice == 1) {
                playerNum++;
                cout<<"Please choose your strategy: 1. Remainder after addition, 2. Remainder after multiplication, 3. Average."<<endl;
                unsigned s;
                cin>>s;
                gameSessions.back()->accept(user, getStrategy(s));
                //gameSessions.back()->accept()
            }
        }
    }
    if (playerNum >= 2) {
        gameSessions.back()->play();
    }else{
        cout<<"Not enough player. Start again?"<<endl;
    }
}
