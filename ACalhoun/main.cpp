/*
Made by Allison Calhoun

Displays the salary

Edit : Kyle Seidlitz 
Removed System("pause");
Changed setprecision from 4 to 2
*/
#include <iostream>
//needs another include here
using namespace std;


int main()
{
    //declare variables
    double currentPay    = 0.0;
    double currentHours  = 0.0;

    //get input items

    cout << "Current salary (per hour): $";
    cin >> currentPay;
    cout << "\nHow many hours did you work this pay period:";
    cin >> currentHours;

    currentPay = currentPay * currentHours;

    //system("pause"); //Problem here
    //display the pay
    cout <<endl;
    cout << fixed << setprecision(2); //This is set wrong
    cout << "Gross pay this pay period: $" << currentPay << endl;

    return 0;

    //end of main function

}

