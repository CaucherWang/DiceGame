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

#endif /* IStrategy_h */
