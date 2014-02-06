#include "main.h"
using namespace std;
/**
* Filename: main.cpp
* Author: James Narayana Emery
* Date: 4/20/2013
* Purpose: Converting Decimals to Roman Numerals.
*/
int main()
{
    int user=24;
    Numeral nums[10];
    string sets[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX"};

    //Set roman numerals to their respective strings
    for(int i = 0; i <=19; i++)
    {
        nums[i]->setroman(sets[i]);
    }


    //display users selected numeral
    while(user != 0)
    {
        cout << "Convert Decimal to Roman Numeral: ";
        cin >> user;
        if((1 <= user)and(user <= 20)) cout << "Roman Numeral equivalent is " << nums[user-1].getroman() << "\n" << endl;

}
