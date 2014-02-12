/*  Kristian Strickland
    CS246 - W14

    GitHub Assignment

    **Bug 1 : function prototype has an improperly declared variable.
    **Bug 2 : float variable in funcion calcOdds should be initialized to 1.0.
*/
#include <iostream>

using namespace std;
float calcOdds(input);
int main()
{
    int input;
    float odds;
    cout << "This program calculates the probability of flipping a coin\n";
    cout << "and having land on all heads or all tails in a row\n\n";

    cout << "How many times should the coin be flipped? ";

    cin >> input;

    odds = calcOdds(input);

    cout << "\nThe odds of a coin landing on all heads or all tails " << input  << endl;
    cout << "Times in a row is " << odds *100 << " Percent." << endl;
}
float calcOdds(int input)
{
    float odds = .5;        // odds variable is improperly initialized.  Should be changed to 1.0;
    for(int i = 0; i < input; i++)
        odds *=0.5;
    return odds;
}
