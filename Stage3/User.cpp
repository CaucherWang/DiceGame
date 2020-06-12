#include "User.h"


void User::printCreditRecords(){
    for(auto c: creditRecords){
        c->printRecord();
    }
}

void User::changeCredits(int credit, event e){
    auto p = make_shared<CreditRecord>();
    p->eventName = e;
    p->setTime();
    p->creditChange = credit;
    creditRecords.push_back(p);
    credits += credit;
}
