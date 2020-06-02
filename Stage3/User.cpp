//
//  User.cpp
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#include "User.h"


void User::printCreditRecords(){
    for(auto c: creditRecords){
        c->printRecord();
    }
}

void User::changeCredits(int c, event e){
    auto p = make_shared<CreditRecord>();
    p->eventName = e;
    p->setTime();
    p->creditChange = c;
    creditRecords.push_back(p);
    credits += c;
}
