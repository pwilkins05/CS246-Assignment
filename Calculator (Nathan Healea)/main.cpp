/***************************
** Created by Nathan Healea
** Date Created : 2/10/2014
** Date Last Edited: 2/10/2014 8:01 pm

** file name: main.cpp

** Memo

To do's
    1) Multiply() function does not return the right number.
    2) program only runs once. Add an interface where a user can
        enter number and then call a function.
    3) Once 2 is completed make the program loop where a user can keep entering numbers
        and keep doing calculations.

RULES:
    Do not use math short cuts, right could that would do the problem by hand.
****************************/
#include <iostream>
#include "Calulator.h"
using namespace std;

int main()
{
    Calulator Calc;
    Calc.setFirstNum(10);
    Calc.setSecondNum(2);

    cout << Calc.getFistnum() << " + " << Calc.getSecondNum() << " = " << Calc.Add() << "\n";
    cout << Calc.getFistnum() << " - " << Calc.getSecondNum() << " = " << Calc.Subtract() << "\n";
    cout << Calc.getFistnum() << " * " << Calc.getSecondNum() << " = " << Calc.Multiply() << "\n";
    cout << Calc.getFistnum() << " / " << Calc.getSecondNum() << " = " << Calc.Divide() << "\n";


    return 0;
}
