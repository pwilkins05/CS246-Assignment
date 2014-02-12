///This program was created by Matthew Bernik
///**BUGS**///
///LINE  26: MISSING SEMICOLON....FIXED BY...
///LINE 134: VARIABLE TYPE MISSING, NEEDS VARIABLE TYPE STRING INFRONT OF VARIABLE SIGN....FIXED BY...
///LINE  30: MISSING SEMICOLON....FIXED BY...
#include <iostream>
#include <string>

using namespace std;
bool checkMonth(int month);
bool checkDay(int month, int day);
std::string zodiacSign(int month, int day);

int main()
{
    int month = 0;
    int day = 0;
    int year = 0;
    char answer = '0';

    cout << "Hello! This program will tell you what astrological sign you are." << endl;

    do{
        cout << "Ok, tell me your date of birth in this format." << endl;
        cout << "MM DD YYYY" << endl;
        cin >> month >> day >> year;

        while(!checkMonth(month)){
            cout << "The month you entered is not a valid month. Please input a valid month." << endl;
            cin >> month
        }

        while(!checkDay(month, day)){
            cout << "The day you entered is not a valid day. Please input a valid day." << endl;
            cin >> day;
        }

        cout << "You entered " << month << "/" << day << "/"<< year << " is this correct? Y/N  ";
        cin >> answer;

        ///VALIDATE ANSWER///
        while(answer != 'Y' && answer != 'N'){
            cout << "I'm sorry. Please enter a Y for yes or a N for no." << endl;
            cin >> answer;
        }

    ///LOOP IF NOT CORRECT INPUT///
    }while(answer == 'N');

    cout << "Your astrological sign is " << zodiacSign(month, day) << "!" << endl;

    return 0;
}

bool checkMonth(int month){
    bool correctInput = true;

    if(month < 1 || month > 12){
        correctInput = false;
    }
return correctInput;
}

bool checkDay(int month, int day){
    bool correctInput = true;

    switch(month){
    case 1:
        if(day < 1 || day > 31){
            correctInput = false;
        }
    break;
    case 2:
        if(day < 1 || day > 29){
            correctInput = false;
        }
    break;
    case 3:
        if(day < 1 || day > 31){
            correctInput = false;
        }
    break;
    case 4:
        if(day < 1 || day > 30){
            correctInput = false;
        }
    break;
    case 5:
        if(day < 1 || day > 31){
            correctInput = false;
        }
    break;
    case 6:
        if(day < 1 || day > 30){
            correctInput = false;
        }
    break;
    case 7:
        if(day < 1 || day > 31){
            correctInput = false;
        }
    break;
    case 8:
        if(day < 1 || day > 31){
            correctInput = false;
        }
    break;
    case 9:
        if(day < 1 || day > 30){
            correctInput = false;
        }
    break;
    case 10:
        if(day < 1 || day > 31){
            correctInput = false;
        }
    break;
    case 11:
        if(day < 1 || day > 30){
            correctInput = false;
        }
    break;
    case 12:
        if(day < 1 || day > 31){
            correctInput = false;
        }
    break;
    }

return correctInput;
}

string zodiacSign(int month, int day){
    sign = "";

    switch(month){
    case 1:
        if(day >= 1 && day <= 19){
            sign = "Capricorn";
        }
        else{
            sign = "Aquarius";
        }
    break;
    case 2:
        if(day >= 1 && day <= 18){
            sign = "Aquarius";
        }
        else{
            sign = "Pisces";
        }
    break;
    case 3:
        if(day >= 1 && day <= 20){
            sign = "Pisces";
        }
        else{
            sign = "Aries";
        }
    break;
    case 4:
        if(day >= 1 && day <= 19){
            sign = "Aries";
        }
        else{
            sign = "Taurus";
        }
    break;
    case 5:
        if(day >= 1 && day <= 20){
            sign = "Taurus";
        }
        else{
            sign = "Gemini";
        }
    break;
    case 6:
        if(day >= 1 && day <= 20){
            sign = "Gemini";
        }
        else{
            sign = "Cancer";
        }
    break;
    case 7:
        if(day >= 1 && day <= 22){
            sign = "Cancer";
        }
        else{
            sign = "Leo";
        }
    break;
    case 8:
        if(day >= 1 && day <= 22){
            sign = "Leo";
        }
        else{
            sign = "Virgo";
        }
    break;
    case 9:
        if(day >= 1 && day <= 22){
            sign = "Virgo";
        }
        else{
            sign = "Libra";
        }
    break;
    case 10:
        if(day >= 1 && day <= 22){
            sign = "Libra";
        }
        else{
            sign = "Scorpio";
        }
    break;
    case 11:
        if(day >= 1 && day <= 21){
            sign = "Scorpio";
        }
        else{
            sign = "Sagittarius";
        }
    break;
    case 12:
        if(day >= 1 && day <= 21){
            sign = "Sagittarius";
        }
        else{
            sign = "Capricorn";
        }
    break;
    }

return sign;
}
