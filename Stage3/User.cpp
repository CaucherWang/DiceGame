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
