#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

/*******************************
 *
 * Yahtzee
 *
 * Starter code by Paul Wilkins
 * Last Modified: 02/09/2014 1:20pm
 *
 * Edit: Fixed up grammar errors and implemented the scoring
 *   algorithms for 1-6. The rest of the algorithms still need to be
 *   filled out by somebody. (Line 228)
 *
 * Edit: Narayana Emery
 **  Changed Dice to array**
 *
 * Edit: Nalani Sanderson
 **  Added function rollDie to fix
 **     bug (dice not displaying
 **     correct value)
 *
 * Edit:Jackson Hall
 **Fixed the infinite loop caused by invalid
 **scoring choice input
 *
 *
 * Edit:Coral Breding
 ** the game was on an endless loop of play
 * added a exit condition 2/10/14

 * Edit: Duncan M. Luiten
    made it so selecting the rerolls for dice goes faster.
    instead of inserting a Y or N for each line.
    You insert 5 Y or N's in a row. like this: YNNYY.
    that will change values 1, 4, and 5.


 ** added a exit condition 2/10/14
 *
 * Edit: Nathan Healea Modified (12:53 2/10/2014)
 ** Fix the exit condition that Coral created
 *
 * Edit: Stefan Reindel
 ** Worked on scoreOnes(int ones,int twos,int threes,int fours ,int fives,int sixes)
 ** Worked on scoreTwos(int ones,int twos,int threes,int fours ,int fives,int sixes)
 ** Worked on scoreThrees(int ones,int twos,int threes,int fours ,int fives,int sixes)
 *
 * Edit:Matthew Bernik
 ** There was no validation for the players playing choice
 ** Added Validation loop 2/10/14
 *
 *Edit: Alex Crippen
 **Cleaned up file, added note
 *
 *Edit: Kristian Strickland - 2/11/14
 *  Cleaned up Y/N verification.  Program will accept lower case y and n.
 *  Changed Initial starting loop to accept a 'Start' bool.
 *******************************/

// TODO: switch to using arrays for scores
// TODO switch to using array for dice: Narayana Emery
// TODO: add yahtzee bonus score
// TODO: implement scoring functions (see switch statement, line 125)
// BUG: if a char is typed as input for "Which category would you like to score this as?"
//          enters an infinite loop (function getScoreOption)

using namespace std;

void printRoll(int dice[]);
std::string askReroll();
void printSeparator();
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
                int fivesScore, int sixesScore, int threeOfAKind,
                int fourOfAKind, int fullHouse, int smallStraight,
                int largeStraight, int yahtzee, int chance);
void printScoreLine(string name, int score);
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
                   int fivesScore, int sixesScore, int threeOfAKind,
                   int fourOfAKind, int fullHouse, int smallStraight,
                   int largeStraight, int yahtzee, int chance);
int tabulateDice(int n, int dice[]);
int rollDie();

const int NUM_CATEGORIES = 13;
const int SIDES = 6;
const int EMPTY = -1;
enum Category { ONES = 1, TWOS, THREES, FOURS, FIVES, SIXES, THREE_OF_A_KIND,
                    FOUR_OF_A_KIND, FULL_HOUSE, SMALL_STRAIGHT, LARGE_STRAIGHT,
                    YAHTZEE, CHANCE };

int main()
{
	///FIXED///
    int die[5];
    char redo1, redo2, redo3, redo4, redo5;



    int onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore;
    int threeOfAKind;
    int fourOfAKind;
    int fullHouse;
    int smallStraight;
    int largeStraight;
    int yahtzee;
    int chance;
    char choice;
    bool play = false;
    bool start = false;


    onesScore = twosScore = threesScore = foursScore = fivesScore = sixesScore = EMPTY;
    threeOfAKind = fourOfAKind = fullHouse = smallStraight = largeStraight = yahtzee = chance = EMPTY;

    cout << "Welcome to Yahtzee!" << endl;
    srand(time(0));

    cout << "Would you like to play? Y for yes, N for no." << endl;

     ///ADDED VALIDATION LOOP FOR THE PLAYERS PLAYING CHOICE///
     do{

        cin >> choice;
        if (choice == 'Y' or choice == 'y')
        {
            start = true;
            play = true;
            cout << "Play" << endl;
        }
        else if (choice == 'N' or choice ==  'n')
        {
            play = false;
            start = true;
            cout << "Goodbye!" << endl;
        }
        else
        {
            cout << "Im sorry, please enter a Y for yes, or a N for no." << endl;
        }
        }while(!start);
        ///END OF VALIDATION///

    int ones, twos, threes, fours, fives, sixes;
    while (play)
    {


    for (int turn = 0; turn < NUM_CATEGORIES; turn++)
    {
        int round = 1;
        ones = twos = threes = fours = fives = sixes = 0;
		for ( int i = 0; i < 5; i++ ) die[i] = rollDie();

        printRoll(die);

        do
        {
            std::string diceList = askReroll();

            redo1 = diceList[0];
            redo2 = diceList[1];
            redo3 = diceList[2];
            redo4 = diceList[3];
            redo5 = diceList[4];

            if (redo1 == 'Y' or redo1 == 'y')
            {
                die[0] = rollDie();
            }
            if (redo2 == 'Y' or redo2 == 'y')
            {
                die[1] = rollDie();
            }
            if (redo3 == 'Y' or redo3 == 'y')
            {
                die[2] = rollDie();
            }
            if (redo4 == 'Y' or redo4 == 'y')
            {
                die[3] = rollDie();
            }
            if (redo5 == 'Y' or redo5 == 'y')
            {
                die[4] = rollDie();
            }

            printRoll(die);
            round++;

        } while ((redo1 || redo2 || redo3 || redo4 || redo5) && round < 3);

        ones = tabulateDice(1, die);
        twos = tabulateDice(2, die);
        threes = tabulateDice(3, die);
        fours = tabulateDice(4, die);
        fives = tabulateDice(5, die);
        sixes = tabulateDice(6, die);


        int scoreOption = getScoreOption(onesScore, twosScore, threesScore, foursScore,
                                         fivesScore, sixesScore, threeOfAKind,
                                         fourOfAKind, fullHouse, smallStraight,
                                         largeStraight, yahtzee, chance);

        switch (scoreOption)
        {
            case ONES:
                onesScore = ones;
                break;
            case TWOS:
                twosScore = twos * 2;
                break;
            case THREES:
                threesScore = threes * 3;
                break;
            case FOURS:
                foursScore = fours * 4;
                break;
            case FIVES:
                fivesScore = fives * 5;
                break;
            case SIXES:
                sixesScore = sixes * 6;
                break;
            case THREE_OF_A_KIND:
                threeOfAKind = scoreThreeOfAKind(ones, twos, threes, fours, fives, sixes);
                break;
            /*case FOUR_OF_A_KIND:
                fourOfAKind = scoreFourOfAKind(ones, twos, threes, fours, fives, sixes);
                break;
            case FULL_HOUSE:
                fullHouse= scoreFullHouse(ones, twos, threes, fours, fives, sixes);
                break;
            case SMALL_STRAIGHT:
                smallStraight = scoreSmallStraight(ones, twos, threes, fours, fives, sixes);
                break;
            case LARGE_STRAIGHT:
                largeStraight = scoreLargeStraight(ones, twos, threes, fours, fives, sixes);
                break;
            case YAHTZEE:
                yahtzee = scoreYahtzee(ones, twos, threes, fours, fives, sixes);
                break;
            case CHANCE:
                chance = scoreChance(ones, twos, threes, fours, fives, sixes);
                break;*/
        }

        printScore(onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore,
                   threeOfAKind, fourOfAKind, fullHouse, smallStraight, largeStraight, yahtzee, chance);

    }
    cout << "would you like to play? Y for yes N for no." << endl;
    cin >> choice;
    if (choice == 'n' || choice == 'N')
    {
        play = false;
    }
    else if(choice  == 'y' || choice == 'Y')
    {
        play = true;
    }
}
}

/*********************************************************
 *
 * printRoll
 * ------------------
 * This function prints out the current state of the dice,
 * with blank lines before and after the print-out.
 *
 *********************************************************/
void printRoll(int dice[])
{
    cout << endl;
    cout << "Your roll is:" << endl;
	cout << dice[0] << " " << dice[1] << " " << dice[2] << " " << dice[3] << " " << dice[4] << endl;
    cout << endl;
}

/*********************************************************
 *
 * askReroll
 * ------------------
 * This function ask the user if they'd like to reroll one
 * of the dice.  The function takes an integer which is
 * the number of the die being rerolled, and returns true if
 * the die should be rerolled, false otherwise.  The integer
 * argument is used only for instruction display, this function
 * does not actually reroll any dice.  Responses accepted are
 * 'Y' 'y' and 'N' 'n'.
 *
 *********************************************************/
std::string askReroll()
{
    bool validator = false;
    std::string choice = "";
    while (validator == false)
    {
        cout << "Would you like to reroll dice\n";
        cout << "Type (Y for Yes and N for No) in the format ***** for dice 12345\n";
        cout << "(for example YYNNY, changes dice 1,2 and 5)\n\n";
        cin >> choice;

        validator = true;

        for(unsigned int i = 0; i < choice.length(); i++)
        {
        if ( (choice[i] != 'N') && (choice[i] != 'n') && (choice[i] != 'Y') && (choice[i] != 'y') ) {validator = false;}
        }

        if (validator == false){std::cout << "Please insert valid letters. 'Y' or 'N'.\n";}

        if (choice.length() > 5)
            {
                std::cout << endl << "*Too many letters*";
                validator = false;
            }

        if (choice.length() < 5)
            {
                std::cout << endl << "*Too few letters*";
                validator = false;
            }
    }

    return choice;
}



/********************************
 *
 * printScore
 * --------------------
 * This function prints out the complete score table
 * for the yahtzee game in its current state.
 *
 ********************************/
void printScore(int onesScore, int twosScore, int threesScore, int foursScore,
                int fivesScore, int sixesScore, int threeOfAKind,
                int fourOfAKind, int fullHouse, int smallStraight,
                int largeStraight, int yahtzee, int chance)
{
    printSeparator();
    printScoreLine("Ones", onesScore);
    printSeparator();
    printScoreLine("Twos", twosScore);
    printSeparator();
    printScoreLine("Threes", threesScore);
    printSeparator();
    printScoreLine("Fours", foursScore);
    printSeparator();
    printScoreLine("Fives", fivesScore);
    printSeparator();
    printScoreLine("Sixes", sixesScore);
    printSeparator();
    printScoreLine("Three of a kind", threeOfAKind);
    printSeparator();
    printScoreLine("Four of a kind", fourOfAKind);
    printSeparator();
    printScoreLine("Full House", fullHouse);
    printSeparator();
    printScoreLine("Small Straight", smallStraight);
    printSeparator();
    printScoreLine("Large Straight", largeStraight);
    printSeparator();
    printScoreLine("Yahtzee", yahtzee);
    printSeparator();
    printScoreLine("Chance", chance);
    printSeparator();
}

/********************************
 *
 * printSeperator
 * --------------------
 * This helper function prints out a single
 * separator line used as part of the score
 * printing function.
 *
 ********************************/
void printSeparator()
{
    cout << "+-------------------+-------+" << endl;
}

/********************************
 *
 * printScoreLine
 * --------------------
 * This function prints out a single line of the score.
 * The string argument is the name of the category, while
 * the in is the value of the score.  The category name is left
 * aligned, while the score value is right aligned.
 *
 ********************************/
void printScoreLine(string name, int score)
{
    cout << "| " << left << setw(18) << name << "| ";
     if (score >=0)
     {
         cout << right << setw(5) << score;
     }
     else
     {
         cout << "     ";
     }
     cout << " |" << endl;
}

/********************************
 *
 * getScoreOption
 * --------------------
 * This function gets the score category which the player wishes to score
 * with the current roll.  The function ensures that the response corresponds
 * to a valid category.  It also check to make sure that the selected category
 * has not yet been scored (unscored categories contain the value EMPTY).
 *
 ********************************/
int getScoreOption(int onesScore, int twosScore, int threesScore, int foursScore,
                   int fivesScore, int sixesScore, int threeOfAKind,
                   int fourOfAKind, int fullHouse, int smallStraight,
                   int largeStraight, int yahtzee, int chance)
{
    int ans;
    bool valid = false;
    cout << "Here are the categories: " << endl;
    cout << "1. Ones" << endl;
    cout << "2. Twos" << endl;
    cout << "3. Threes" << endl;
    cout << "4. Fours" << endl;
    cout << "5. Fives" << endl;
    cout << "6. Sixes" << endl;
    cout << "7. Three of a kind" << endl;
    cout << "8. Four of a kind" << endl;
    cout << "9. Full House" << endl;
    cout << "10. Small Straight" << endl;
    cout << "11. Large Straight" << endl;
    cout << "12. Yahtzee" << endl;
    cout << "13. Chance" << endl;
    do
    {
        cout << "How would you like to score this? ";
        cin >> ans;
        while (ans < 0 || ans > NUM_CATEGORIES)
        {
            cout << "Please enter a number between 1 and " << NUM_CATEGORIES << ": ";
            cin >> ans;
        }
        switch (ans)
        {
            case ONES:
                if (onesScore == EMPTY) valid = true;
                break;
            case TWOS:
                if (twosScore == EMPTY) valid = true;
                break;
            case THREES:
                if (threesScore == EMPTY) valid = true;
                break;
            case FOURS:
                if (foursScore == EMPTY) valid = true;
                break;
            case FIVES:
                if (fivesScore == EMPTY) valid = true;
                break;
            case SIXES:
                if (sixesScore == EMPTY) valid = true;
                break;
            case THREE_OF_A_KIND:
                if (threeOfAKind == EMPTY) valid = true;
                break;
            case FOUR_OF_A_KIND:
                if (fourOfAKind == EMPTY) valid = true;
                break;
            case FULL_HOUSE:
                if (fullHouse == EMPTY) valid = true;
                break;
            case SMALL_STRAIGHT:
                if (smallStraight == EMPTY) valid = true;
                break;
            case LARGE_STRAIGHT:
                if (largeStraight == EMPTY) valid = true;
                break;
            case YAHTZEE:
                if (yahtzee == EMPTY) valid = true;
                break;
            case CHANCE:
                if (chance == EMPTY) valid = true;
                break;
        }
        if (!valid)
        {
            cout << "That category has already been used" << endl;
            cin.clear();// Jackson has been here and fixed your loop problem.
            cin.ignore();
        }
    } while (!valid);

    return ans;
}

/********************************
 *
 * tabulateDice
 * --------------------
 * This function calculates and returns the number of dice
 * which show the value n.
 *
 ********************************/
int tabulateDice(int n, int dice[])
{
    int ans = 0;
	for ( int i = 0; i < 5; i++ )
		if ( dice[i] == n ) ans++;
    return ans;
}

/********************************
*
* rollDie
* ---------------------
* This function sets the die value
*
********************************/
int rollDie()
{
    return rand() % SIDES +1;
}

/**************************************
Marian's comment goes here
*///////////////////////////////////////

/*******************************
 * This is a very important message
 * About Nothing at all! Don't Learn to much!
 ******************************/

/*********************
 *
 * Comment by Nathan Johnson for GIT Assignment
 *
 * *******************
*/
/************************************
*	Someone already did my fix,
*	Kyle Seidlitz for GIT assignment
*******************************************/

/**Comment by Allison Calhoun*/

/**Comment by Marti Garcia
Not versed in C++, so wasn't sure what to comment on.
Syntax for Switch statements is C++ are very similar to C#. */

/**Comment by Robert Wright*/

/**Comment by Matt Prenevost
    Removed comment tick from Three_Of_A_Kind function**/

