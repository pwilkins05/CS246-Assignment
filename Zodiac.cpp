/************************
* Zodiac - main.cpp
* This program takes the users birthday
* and calculates their age and western
* zodiac sign.
*
* Author: Nalani Sanderson
* Last Modified: 02/09/14 3:00pm
************************/

/************************
*
* TO-DO: add Chinese zodiac
* Fixed: curMo not setting properly
* Fixed: curYear not setting properly
*
************************/

#include <iostream>
#include <ctime>

using namespace std;

//prototypes
int calcAge(int month, int day, int year, int& msg);
string westZodiac(int month, int day);
void display(int age, string wZod, int msg);

int main()
{
    int month, day, year;
    int age;
    string wZod; //western Zodiac sign
    int msg = 0;

    cout << "Enter your birthday (mm dd yyyy): ";
    cin >> month >> day >> year;

    age = calcAge(month, day, year, msg);
    wZod = westZodiac(month, day);
    display(age, wZod, msg);

}

/**************
* calcAge()
* This function calculates the users age
* based on birthday and today's date
***************/
int calcAge(int month, int day, int year, int& msg)
{
    int curMo, curDay, curYr; //today's date
    int age;

    //set today's date
    time_t t = time(0);   // get time now
    struct tm * now = localtime(&t);
    curMo = now->tm_mon + 1; // Jackson fixed This here
    curDay = now->tm_mday;
    curYr = now->tm_year + 1900; // Jackson fixed This here

    if (month < curMo) //birthday already happened
    { age = curYr - year; }
    else if (month > curMo) //birthday hasn't happened
    { age = curYr - year - 1; }
    else if (month == curMo) //birthday this month
    {
        if (day < curDay) //already happened
            { age = curYr - year; }
        else if (day > curDay) //not yet happened
            { age = curYr - year - 1; }
        else if (day == curDay) //birthday is today!
        {
            age = curYr - year;
            msg = 1;
        }
    }
    return age;
}

/**************
* westZodiac()
* This function determines the user's
* western zodiac sign based on birthday
***************/
string westZodiac(int month, int day)
{
    string zodiac;
    switch (month)
    {
        case 1: if (day <= 19) { zodiac = "Capricorn"; }
            else { zodiac = "Aquarius"; }
            break;
        case 2: if (day <= 18) { zodiac = "Aquarius"; }
            else { zodiac = "Pisces"; }
            break;
        case 3: if (day <= 20) { zodiac = "Pisces"; }
            else { zodiac = "Aries"; }
            break;
        case 4: if (day <= 19) { zodiac = "Aries"; }
            else { zodiac = "Taurus"; }
            break;
        case 5: if (day <= 20) { zodiac = "Taurus"; }
            else { zodiac = "Gemini"; }
            break;
        case 6: if (day <= 20) { zodiac = "Gemini"; }
            else { zodiac = "Cancer"; }
            break;
        case 7: if (day <= 22) { zodiac = "Cancer"; }
            else { zodiac = "Leo"; }
            break;
        case 8: if (day <= 22) { zodiac = "Leo"; }
            else { zodiac = "Virgo"; }
            break;
        case 9: if (day <= 22) { zodiac = "Virgo"; }
            else { zodiac = "Libra"; }
            break;
        case 10: if (day <= 22) { zodiac = "Libra"; }
            else { zodiac = "Scorpio"; }
            break;
        case 11: if (day <= 21) { zodiac = "Scorpio"; }
            else { zodiac = "Sagittarius"; }
            break;
        case 12: if (day <= 21) { zodiac = "Sagittarius"; }
            else { zodiac = "Capricorn"; }
            break;
        default: zodiac = "invalid month";
    }
    return zodiac;
}

/**************
* display()
* This function displays the user's age,
* zodiac signs, and any additional messages
***************/
void display(int age, string wZod, int msg)
{
    cout << "You are " << age << " years old. \n";
    if (msg==1)
        cout << "Happy Birthday! \n";
    cout << "Your zodiac sign is " << wZod << ". \n";
}
