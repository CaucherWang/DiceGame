# Dice Game Final Report

### 静态设计

![6801591953033_.pic_hd](final_report.assets/6801591953033_.pic_hd.jpg)

### 动态行为设计

![6541591948559_.pic_hd](final_report.assets/6541591948559_.pic_hd.jpg)

### 用例测试

- 三位玩家alice, bob, sally加入游戏，分别选择加法、乘法、平均三种策略。每人每次掷骰子前首先查询自己的积分和前几轮的结果，掷骰子后都企图买1个点数。第一次三人都成功购买，第二次只有sally成功购买。
- 正确结果如第二张截图所示。

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
        //Round 2: Player alice divided up 5 points;
        g->removePlayer();
    }
```

![屏幕快照 2020-06-12 下午7.24.53](final_report.assets/屏幕快照 2020-06-12 下午7.24.53.png)

### 迭代设计思路

- 静态类之间的关系说明：系统类为DiceGamePlatform，聚合多个用户，关联多个GameSession。每个用户关联多个玩家，每次加入GameSession时创建玩家，每个玩家实现一个更新积分纪录的接口。每个GameSession关联一个Dice，组合多个Round。每个Round组合多个Turn，实现一个更新积分纪录的接口。每个Turn关联一个玩家，聚合多个更新积分纪录的接口。

- 积分：积分纪录可以看作一个新的数据类型，储存记录时间、改变积分的行为类型和积分改变的数值。每一个用户储存多条记录。积分纪录通过打印方法标准输出。用户类与积分纪录为一对多的聚合关系。
- 积分更新：每一个turn里如果需要购买点数，需要对于round.pointsBet, 和用户的积分纪录进行更新。此处用到了Observer模式。Turn作为subject类，Player和Round通过新建的IUpdatePoints监听积分纪录的更新。
- 计算点数策略：采用Strategy模式，三种积分纪录CAddRemain6, CMultRemain6, CAverage类型实现同一个抽象类接口IStrategy，Player类与计算点数策略为一对一的组合关系。

- 为了更高效地使用随机函数和明确业务逻辑语义，将骰子设计为一个有静态roll方法的抽象类，在GameSession里面调用。

