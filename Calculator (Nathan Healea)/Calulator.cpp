/***************************
** Created by Nathan Healea
** Date Created :
** Date Last Edited:

** file name:

** Memo:

****************************/

#include "Calulator.h"

Calulator::Calulator()
{
    //ctor
    firstNum = 0;
    secondNum = 0;
}

Calulator::~Calulator()
{
    //dtor
}
int Calulator::Add()
{
    return firstNum + secondNum;
}

int Calulator::Subtract()
{
    return firstNum - secondNum;
}

int Calulator::Multiply()
{
    int total = 0;
    for(int i = 0; i < secondNum; i++)
    {
        total += firstNum;
    }
    return total;
}

float Calulator::Divide()
{
    int maxCount = 0;
    int total = firstNum;
    while(maxCount != 6)
    {
        total -= secondNum;
        maxCount++;
    }
        return total;
}

