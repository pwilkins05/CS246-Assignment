#include <iostream>
#include <stdlib.h>
/*

This program is a trivia game centered around curling
errors are at line 31, 67, and

*/

using namespace std;

int checkAnswers(int a, int b, int c, int d, int e)
{
    int correct = 0;
    if(a == 1)
    {
        correct ++;
    }
    if(b == 2)
    {
        correct ++;
    }
    if(c == 2)
    {
        correct ++;
    }
    if(d == 3)
    {
        correct ++;
    }
    if(e = 1) // error should be if(e == 1)
    {
        correct ++;
    }
    return correct;
}

int answerValidator (int A)
{
    int answer = A;
    while(answer != 1 && answer !=2 && answer !=3 && answer !=4)
    {
        cout << "Your answer is invalid try again\n1,2,3 or 4 are viable answers." << endl;
        cin >> answer;
        while(cin.fail() == true)
        {
            cin.clear();
            cin.ignore();
            cout << " Your answer was not an integer please only use whole numbers." << endl;
            cin >> answer;
        }
    }
    return answer;


}

int main()
{
    bool retry;
    bool startBool;
    char startChar;
    char retryChar;
    int ammountPossible = 5;
    int ammountCorrect;
    int answer1, answer2, answer3, answer4;
    char answer5; // answer5 shoudl not have the data type char but instead int
    cout << "This is a trivia game based around Curling\nWould you like to begin Y for yes N for no." << endl;
    cin >> startChar;
    while(cin.fail() == true || (startChar != 'y' && startChar != 'n' && startChar!= 'Y' && startChar != 'N'))
    {
        cin.clear();
        cin.ignore();
        cout << "Your input failed try again.\n Y or N" << endl;
        cin >> startChar;
         // There should be curly brackets here

        if(startChar == 'y' || startChar == 'Y')
        {
        startBool = true;
        }
        else if(startChar == 'n' || startChar == 'N')
        {
        startBool = false;
        }

    if (startBool == true)
    {
        do
        {
            system("cls");
            cout << "Question 1: What is the formal term for a curling team\n    1:Rink\n    2:Squad\n    3:Team\n    4:Unit" << endl;
            cin >> answer1;
            while(cin.fail() == true)
            {
                cin.clear();
                cin.ignore();
                cout << " Your answer was not an integer please only use whole numbers." << endl;
                cin >> answer1;
            }
            answer1 = answerValidator(answer1);
            system("cls");

            cout << "Question 2: The team that curls their stones closest\nto this part of the ice scores points\n    1:Button\n    2:Pin\n    3:Bullseye\n    4:Goal" << endl;
            cin >> answer2;
            while(cin.fail() == true)
            {
                cin.clear();
                cin.ignore();
                cout << " Your answer was not an integer please only use whole numbers." << endl;
                cin >> answer2;
            }
            answer2 = answerValidator(answer2);
            system("cls");

            cout << "Question 3: What is the term used for the rounds teams play\n    1:Round\n    2:End\n    3:Quarter\n    4:Inning" << endl;
            cin >> answer3;
            while(cin.fail() == true)
            {
                cin.clear();
                cin.ignore();
                cout << " Your answer was not an integer please only use whole numbers." << endl;
                cin >> answer3;
            }
            answer3 = answerValidator(answer3);
            system("cls");

            cout << "Question 4: If you have the hammer what does that mean\n    1:You have the first throw\n    2:You have and extra throw\n    3:You have the last throw\n    4:Your last throw is with a heavier stone" << endl;
            cin >> answer4;
            while(cin.fail() == true)
            {
                cin.clear();
                cin.ignore();
                cout << " Your answer was not an integer please only use whole numbers." << endl;
                cin >> answer4;
            }
            answer4 = answerValidator(answer4);
            system("cls");

            cout << "Question 5: Who won the last gold medal in the olympics for mens curling\n    1:Canada\n    2:Sweden\n    3:Norway\n    4:Switzerland" << endl;
            cin >> answer5;
            while(cin.fail() == true)
            {
                cin.clear();
                cin.ignore();
                cout << " Your answer was not an integer please only use whole numbers." << endl;
                cin >> answer5;
            }
            answer5 = answerValidator(answer5);
            system("cls");

            ammountCorrect = checkAnswers(answer1, answer2, answer3, answer4, answer5);

            cout << "you got " << ammountCorrect << "out of " << ammountPossible << "correct." << endl;
            cout << "would you like to try again\n Y or N" << endl;
            cin >> retryChar;
            while(cin.fail() == true || (retryChar != 'y' && retryChar != 'n' && retryChar != 'Y' && retryChar != 'N'))
            {
                cin.clear();
                cin.ignore();
                cout << "Your input failed try again.\n Y or N" << endl;
                cin >> retryChar;
            }

            if(retryChar == 'y' || retryChar == 'Y')
            {
            retry = true;
            }
            else if(retryChar == 'n' || retryChar == 'N')
            {
            retry = false;
            }
        }while(retry == true);
    }

    return 0;
}

