```c++
		int dice[] = {1,2,6,4,5,6,3,2,3,6,6,2};
    int i = 0;
    shared_ptr<User> u1 = make_shared<User>("alice");
    u1->changeCredits(5, REGISTER);
    shared_ptr<User> u2 = make_shared<User>("bob");
    u2->changeCredits(5, REGISTER);
    shared_ptr<User> u3 = make_shared<User>("sally");
    u3->changeCredits(5, REGISTER);
    IStrategy* s1 = new CAddRemaind6();
    IStrategy* s2 = new CMutRemaind6();
    IStrategy* s3 = new CAverage();
    const Dice d;
    GameSession* g = new GameSession(d);
    g->accept(u1, s1);
    g->accept(u2,s2);
    g->accept(u3,s3);
    for(int roundIndex  = 0; roundIndex < 2; roundIndex++){
        shared_ptr<Round> r = g->startRound(roundIndex);
        auto turns = r->getTurns();
        for(auto turn : turns){
            g->playMove(turn, 2);
            g->playMove(turn, 4);
            unsigned p1 = dice[i++]; //1;6;5;3;3;6
            unsigned p2 = dice[i++]; //2;4;6;2;6;2
            cout<<turn->setPoints(p1,p2)<<endl; //4;1;5;6;1;4
            //all buy 1 points
            turn->modify_n(1);
        }
        r->finish();
        r->printRoundResult();
        //Round 1: Player sally divided up 9 points;
        //Round 2: Player alice divided up 6 points;
        g->removePlayer();
    }
```

