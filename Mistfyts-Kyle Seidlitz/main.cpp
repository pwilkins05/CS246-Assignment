#include <iostream>

using namespace std;

int main()
{
    cout << "Hello Everyone!!" << endl;
    cout << "Im very glad that this code doesn't need to do much, because it is awfully late in the scheme of things," << endl;
    cout << "To write that new version of a doubly-linked, double ended queue I've been thinking about." << endl;

// Bug: The formula is supposed to create a value for i such that the cout statement doesnt appear.
    for (int i=0;i<25;i++)
    {
        int a = i;
        if (a>= 3) a = a*2/i;
        else
        {
            i=-2*(a^3)*((-3)^3);
            if (i < -25)
            {
                i  = -i;
            }
            continue;
        }
        cout << "What!! Another Stub?" << endl;
    }


    // Bug: There is no validation for this portion of the code.
    int number = 0;
    cout << "Enter a number between 0 and 100" << endl;
    cin >> number;
    switch (number)
    {
    case 0:
        cout << "Really, thats the best you can do?" << endl;
        break;

    case 23:
        cout << "Well it is prime. I can say that much for it." << endl;
        break;

    case 32:
        cout << "You're getting closer." << endl;

    }
    return 0;
}
