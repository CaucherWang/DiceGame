//
//  IStrategy.h
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#ifndef IStrategy_h
#define IStrategy_h

#include <stdio.h>
class IStrategy{

public:
    virtual unsigned calculatePoints(unsigned p1,unsigned p2) = 0;
};

class CAddRemaind6:public IStrategy
{
public:
    virtual unsigned calculatePoints(unsigned p1,unsigned p2) override;
};

class CMutRemaind6:public IStrategy
{
public:
    virtual unsigned calculatePoints(unsigned p1,unsigned p2) override;
};


class CAverage:public IStrategy
{
public:
    virtual unsigned calculatePoints(unsigned p1,unsigned p2) override;
};

/*
 class Singleton
 {
 private:
 static Singleton instance;
 private:
 Singleton();
 ~Singleton();
 Singleton(const Singleton&);
 Singleton& operator=(const Singleton&);
 public:
 static Singleton& getInstance() {
 return instance;
 }
 }
 
 // initialize defaultly
 Singleton Singleton::instance;
 */
#endif /* IStrategy_h */
