#ifndef Dice_h
#define Dice_h

#include <stdio.h>
#include <cstdlib>

static unsigned int randomNum(int x)
{
    return rand()%x+1;
}

class Dice
{
public:
    static unsigned roll(){
        return randomNum(6);
    }
};

#endif /* Dice_h */
