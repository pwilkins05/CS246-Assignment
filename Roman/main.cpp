#include "main.h"
#include "numeral.h"
using namespace std;
/**
* Filename: main.cpp
* Author: James Narayana Emery
* Date: 4/20/2013
* Purpose: Converting Decimals to Roman Numerals.

*Coral Breding
* Edit 2/10/14
* class was missing in the includes numeral class - fixed
* While loop was missing a bracket - fixed
* setRoman took an int as an argument, it needed to take a string - fixed
*
*Nalani Sanderson
* Edit 2/10/14
* Fixed bug where numbers >10 were displaying incorrectly
*   (made nums[] size=20 instead of size=10)
* Removed "main.h" - not used, unnecessary file
*/

int main()
{
    int user=-1;
    Numeral nums[20];
    string sets[] = {"I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX"};

    //Set roman numerals to their respective strings
    for(int i = 0; i <=19; i++)
    {
        nums[i].setroman(sets[i]);
    }


    //display users selected numeral
    while(user != 0)
    {
        cout << "Convert Decimal to Roman Numeral: ";
        cin >> user;
        if((1 <= user)and(user <= 20)) cout << "Roman Numeral equivalent is " << nums[user-1].getroman() << "\n" << endl;

    }
}
