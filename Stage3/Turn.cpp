//
//  Turn.cpp
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#include "Turn.h"
#include <iostream>
using namespace std;

unsigned Turn::setPoints(unsigned int p1, unsigned int p2){
    points = player->calPoints(p1, p2);
    return points;
}
    
    

unsigned Turn::modifyPoints(){
    unsigned choice = 2;
    unsigned p = 0;
    cout<<player->getName()<<" do you want to buy more points? 1.Yes, 2.No"<<endl;
    cin>>choice;
    if(choice == 1){
        cout << "How much do you want to buy?"<<endl;
        cin >> p;
        if((points + p) > 6 || 2 * p > player->getCredits()){
            cout << "Failed to buy."<<endl;
        }else{
            points += p;
            player->changeCredits(-p * 2, BUYPOINTS);
            cout << "Your points in this turn after buying is "<<points<<endl;
        }
    }
    return p;
}
