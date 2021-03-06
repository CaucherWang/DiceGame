
#ifndef User_h
#define User_h

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;
enum event {REGISTER, BETTING, BUYPOINTS, WINGAME};

struct CreditRecord{
    tm *localTime;
    event eventName;
    int creditChange;
    void setTime(){
        time_t now = time(0);
        localTime = new tm();
        localtime_r(&now, localTime);
    }
    void printRecord(){
        cout<<localTime->tm_year + 1900<<"/"<<localTime->tm_mon + 1<<"/"<<localTime->tm_mday<<" "<<localTime->tm_hour<<":"<<localTime->tm_min<<":"<<localTime->tm_sec<<" ";
        switch(eventName){
                case REGISTER:
                cout<<"注册"<<" ";
                break;
            case BETTING:
                cout<<"下注"<<" ";
                break;
            case BUYPOINTS:
                cout<<"购买点数"<<" ";
                break;
            case WINGAME:
                cout<<"赢得游戏"<<" ";
                break;
        }
        if(creditChange > 0){
            cout << "+";
        }
        cout<< creditChange<<endl;
    }
};

class User{
private:
    string name;
    vector<shared_ptr<CreditRecord>> creditRecords;
    int credits;
public:
    User(string name):name(name), credits(0){
    }
    string getName(){
        return name;
    }
    bool hasOneCredit(){
        return credits >= 1;
    }    
    void changeCredits(int c, event e);
    
    int getCredits(){return credits;}
    void printCreditRecords();
};



#endif /* User_h */
