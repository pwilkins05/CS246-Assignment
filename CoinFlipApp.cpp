/**
* Author: Stefan Reindel
* Date: 2-10-2014
*
* This is a app that simulates the flipping of a coin and keeps track of its stats


* Any Additions Put Info Below VV
*/

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void displayInstructions();
int getOption();
bool flipCoin();
void displayStats(int tHeads, int tTails, float  tFlips);

int main()
{
    srand(time(0));
    bool done = false;
    int totalHeads = 0, totalTails = 0;
    float totalFlips = 0;
    while (!done)
    {
        cout << "\nRound: " << ++totalFlips << "\n";
        displayInstructions();
        switch(getOption())
        {
        case 1:
            if (flipCoin())///Coin Lands heads
            {
                totalHeads++;
            }
            else///Coin Lands Tails
            {
                totalTails++;
            }
            totalFlips;
            displayStats(totalHeads, totalTails, totalFlips);
            break;

        case 2:
            totalHeads = totalTails = totalFlips = 0;
            displayStats(totalHeads, totalTails, totalFlips);
            cout << "\n***RESET VALUES***\n";

            break;

        default:
            displayStats(totalHeads, totalTails, totalFlips);
            cout << "\nExiting Program\n";
            done = true;
            break;

        }
    }
    cout << "\nThanks for playing my coin flip app.\n";
    return 0;
}
/**
*       Dah FUNCTIONS
*/

/**
This functions displays the instructions of the app on screen
*/
void displayInstructions()
{
    cout << "Here are the instructions:\n"
    << "Type \"Y\" to flip the coin.\n"
    << "Type \"R\" to reset the stats.\n"
    << "Type \"N\" to quit the app.\n";
    return;
}
/**
This functions gets the player's choice of option, returning an int for the selection
* INPUT: The user should input a "Y" for a con flip, a "R" for a reset of statistics, and a "N" for exiting the program
* POSSIBLE CHANGES: You could make it so you type in "flip", "reset", and "exit" instead of the given ones
*/
int getOption()
{
    //*
    do{
    string option;
    cout << "Please enter an option: ";
    cin >> option;
    // Jackson hall fixed this
    if (option == "Y" || option == "y")
        return 1;
    if (option == "R" || option == "r")
        return 2;
    if (option == "N" || option == "n")
        return 3;
    cout << "\n";
    displayInstructions();
    cout << "\nPlease enter a valid option: ";
    }while(true);
}

/**
This functions displays the instructions of the app on screen
*/
bool flipCoin()
{
    return rand() % 2;
}
/**
This functions displays the stats.
*/
void displayStats(int tHeads, int tTails, float  tFlips)
{
    cout << "Total Flips: " << tFlips << "\n"
    << "Total Heads: " << tHeads << "\n"
    << "Heads Percentage: " << setprecision(3) << ((tHeads/tFlips)*100) << "\n"
    << "Total Tails: " << tTails << "\n"
    << "Tails Percentage: " << setprecision(3) << ((tTails/tFlips)*100) << "\n";
    return;
}

