/**
* Original (broken) code by Joshua Evans
* KNOWN BUGS: 
** Fixed: Game sometimes doesn't allow the user to guess before finishing: Narayana Emery Feb 12th 10:39
** Fixed: Random number is repeated on multiple playthroughs: Narayana Emery Feb 12th 10:28
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "stdafx.h"

void openingText();
int getRandom();
int getGuess();
bool highLow(int n, int g);
void endText();

int _tmain(int argc, _TCHAR* argv[])
{
	int guess;
	int num;
	bool win = false;
	srand(time ( NULL ));
	openingText();
	num = getRandom();
	while (!win)
	{
		guess = getGuess();
		win = highLow(num, guess);
	}
	endText();
	return 0;
}

void openingText()
{
	std::cout << "Welcome to Number Guess!" << std::endl
		<< "To play, simply guess the randomly chosen number between one and" << std::endl
		<< "one hundred and I will tell you if you are too high or too low!" << std::endl << std::endl;
}

int getRandom()
{
	return rand() % 100 + 1;
}

int getGuess()
{
	int guess = 0;
	std::cout << "Guess a number between one and one hundred: ";
	std::cin >> guess;

	while (guess < 1 || guess > 100)
	{
		std::cout << "Please enter a number between one (1) and one hundred (100): ";
		std::cin >> guess;
	}

	return guess;
}

bool highLow(int n, int g)
{
	if (g < n)
	{
		std::cout << "I'm sorry! You are too low, try again!" << std::endl;
		return 0;
	}	
	else if (g > n)
	{
		std::cout << "I'm sorry! You are too high, try again!" << std::endl;
		return 0;
	}
	else
	{
		std::cout << "You got it!" << std::endl << std::endl;
		return 1;
	}
}

void endText()
{
	std::cout << "Thank you for playing!" << std::endl;
}