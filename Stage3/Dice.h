//
//  Dice.h
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

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
