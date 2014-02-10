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
 * Edit: Narayana Emery
 **  Changed Dice to array**
 *
 * Edit: Nalani Sanderson
 **  Added function rollDie to fix
 **     bug (dice not displaying
 **     correct value)
 *
 * Edit:Coral Breding
 ** the game was on an endless loop of play
 ** added a exit condition 2/10/14
 *
 * Edit: Nathan Healea Modified (12:53 2/10/2014)
 ** Fix the exit condition that Coral created
 *
 * Edit: Stefan Reindel
 ** Worked on scoreOnes(int ones,int twos,int threes,int fours ,int fives,int sixes)
 ** Worked on scoreTwos(int ones,int twos,int threes,int fours ,int fives,int sixes)
 ** Worked on scoreThrees(int ones,int twos,int threes,int fours ,int fives,int sixes)


 **
 *******************************/

// TODO: switch to using arrays for scores
// TODO switch to using array for dice: Narayana Emery
// TODO: add yahtzee bonus score
// TODO: implement scoring functions (see switch statement, line 125)
// BUG: if a char is typed as input for "Which category would you like to score this as?"
//          enters an infinite loop (function getScoreOption)

using namespace std;

void printRoll(int dice[]);
bool askReroll(int n);
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

    int die[5];
    bool redo1, redo2, redo3, redo4, redo5;

    int ones, twos, threes, fours, fives, sixes;

    int onesScore, twosScore, threesScore, foursScore, fivesScore, sixesScore;
    int threeOfAKind;
    int fourOfAKind;
    int fullHouse;
    int smallStraight;
    int largeStraight;
    int yahtzee;
    int chance;
    char choice;
    bool play;


    onesScore = twosScore = threesScore = foursScore = fivesScore = sixesScore = EMPTY;
    threeOfAKind = fourOfAKind = fullHouse = smallStraight = largeStraight = yahtzee = chance = EMPTY;

    cout << "Welcome to Yahtzee!" << endl;
    srand(time(0));

    cout << "would you like to play? Y for yes N for no." << endl;
    cin >> choice;


    if(choice == 'Y')
    {
        cout << "Play " << endl;
    }
    if(choice == 'N')
    {
        play = false;
        cout << "Good bye" << endl;

    }
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
            redo1 = askReroll(1);
            redo2 = askReroll(2);
            redo3 = askReroll(3);
            redo4 = askReroll(4);
            redo5 = askReroll(5);

            if (redo1)
            {
                die[0] = rollDie();
            }
            if (redo2)
            {
                die[1] = rollDie();
            }
            if (redo3)
            {
                die[2] = rollDie();
            }
            if (redo4)
            {
                die[3] = rollDie();
            }
            if (redo5)
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

        /*switch (scoreOption)
        {
            case ONES:
                onesScore = scoreOnes(ones, twos, threes, fours, fives, sixes);
                break;
            case TWOS:
                twosScore = scoreTwos(ones, twos, threes, fours, fives, sixes);
                break;
            case THREES:
                threesScore = scoreThrees(ones, twos, threes, fours, fives, sixes);
                break;
            case FOURS:
                foursScore = scoreFours(ones, twos, threes, fours, fives, sixes);
                break;
            case FIVES:
                fivesScore = scoreFives(ones, twos, threes, fours, fives, sixes);
                break;
            case SIXES:
                sixesScore = scoreSixes(ones, twos, threes, fours, fives, sixes);
                break;
            case THREE_OF_A_KIND:
                threeOfAKind = scoreThreeOfAKind(ones, twos, threes, fours, fives, sixes);
                break;
            case FOUR_OF_A_KIND:
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
                break;
        }*/

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
bool askReroll(int n)
{
    char ch;
    while (true)
    {
        cout << "Would you like to reroll die " << n << "? (Y/N) ";
        cin >> ch;
        switch (toupper(ch))
        {
            case 'Y':
                return true;
            case 'N':
                return false;
            default:
                cout << "Invalid response" << endl;
        }
    }

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
<<<<<<< HEAD
<<<<<<< HEAD

/**
* Score Functions
* scoreOnes
*/
int scoreOnes(int ones,int twos,int threes,int fours ,int fives,int sixes)
{
    return ones;
}
int scoreTwos(int ones,int twos,int threes,int fours ,int fives,int sixes)
{
    return twos * 2;
}
int scoreThrees(int ones,int twos,int threes,int fours ,int fives,int sixes)
{
    return threes * 3;
}

/*******************************
 * This is a very important message
 * About Nothing at all! Don't Learn to much!
 ******************************/
=======
=======
>>>>>>> f82f435abdac8c7d79c424c661ecee7134b2e929
/*********************
 * 
 * Comment by Nathan Johnson for GIT Assignment
 * 
 * *******************
<<<<<<< HEAD
>>>>>>> f82f435abdac8c7d79c424c661ecee7134b2e929
=======
>>>>>>> f82f435abdac8c7d79c424c661ecee7134b2e929
