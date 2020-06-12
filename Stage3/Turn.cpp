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
            player->changeCredits(-2*int(p), BUYPOINTS);
            cout << "Your points in this turn after buying is "<<points<<endl;
        }
    }
    return p;
}
