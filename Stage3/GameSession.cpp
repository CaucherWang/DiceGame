#include "GameSession.h"

void GameSession::accept(shared_ptr<User> user, IStrategy* strategy){
    players.push_back(make_shared<Player>(user, strategy));
}

void GameSession::printRoundResults(){
    for(auto round:rounds){
        round->printRoundResult();
    }
}

void GameSession::removePlayer(){
    auto it = players.begin();
    while (it != players.end()) {
        if ((*it)->getCredits() < 1) {
            it = players.erase(it);
        }else{
            ++it;
        }
    }
}

void GameSession::play(){
    unsigned roundIndex = 0;
    while (!isEnd) {
        startRound(++roundIndex,players);
        auto turns = rounds.back()->getTurns();
        for (auto turn: turns) {
            unsigned move = 2;
            while (move != 1) {
                cout<<turn->getName()<<" Choose your move: 1. roll 2 dices, 2. check your credits, 3. get credit records, 4. get previous round results;"<<endl;
                cin>>move;
                //rounds.back()->getCredits(playMove(turn, move));
            	playMove(turn,move);
            }
        }
        rounds.back()->finish();
        rounds.back()->printRoundResult();
        removePlayer();
        if (players.size() < 2) {
            isEnd = true;
        }
        if(!isEnd){
            unsigned choice = 1;
            cout<<players.at(0)->getName()<<", do you want to end the game? 1. Yes, 2. No."<<endl;
            cin>>choice;
            isEnd = choice == 1;
        }
    }
}



void GameSession::printCurrentCredits(){
    for (int i = 0; i < players.size() - 1; i++) {
        cout << players.at(i)->getName() <<" "<< players.at(i)->getCredits()<<", ";
    }
    cout<<players.back()->getName()<<" "<<players.back()->getCredits()<<endl;
}

unsigned GameSession::playMove(Turn *turn, unsigned int move){
    unsigned credits = 0;
    switch (move) {
        case 1:{
            unsigned p1 = 0, p2 = 0;
            p1 = dice.roll();
            cout <<"First dice result: "<<p1<<endl;
            p2 = dice.roll();
            cout <<"Second dice result: "<<p2<<endl;
            p1 = turn->setPoints(p1, p2);
            cout<<"According to your strategy, your point in this turn is "<<p1<<endl;
            credits = turn->modifyPoints();
            break;
        }
        case 2:{
            cout << "Your current credits: "<<turn->getCredits()<<endl;
            break;
        }
        case 3:{
            turn->printCreditRecords();
            break;
        }
        case 4:{
            printRoundResults();
            cout<<"Credits of current player: "<<endl;
            printCurrentCredits();
            break;
        }
        default:
            break;
    }
    return credits;
}



void GameSession::startRound(unsigned index, vector<shared_ptr<Player>>& players){
    rounds.push_back(make_shared<Round>(index, players));
}
