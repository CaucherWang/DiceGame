//
//  IStrategy.cpp
//  mdice
//
//  Created by apple on 2020/6/1.
//  Copyright © 2020年 Ru Wang. All rights reserved.
//

#include "IStrategy.h"

unsigned CAddRemaind6::calculatePoints(unsigned int p1, unsigned int p2){
    return (p1 + p2) % 6 + 1;
}

unsigned CMutRemaind6::calculatePoints(unsigned int p1, unsigned int p2){
    return (p1 * p2) % 6 + 1;
}

unsigned CAverage::calculatePoints(unsigned int p1, unsigned int p2){
    return (p1 + p2) / 2;
}
