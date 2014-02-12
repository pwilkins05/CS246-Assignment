/**
Author: Corral Breding
title: Array.h
content: contains all prototypes and members of the array class
**/
#ifndef ARRAY_H
#define ARRAY_H
#include <iostream>

static const int SIZE = 100;            // constant variable to decare a max size of 100

class Array
{
    public:
    Array();                       // default constructor
    Array(int s);                   // overloaded constructor
    void setValue(int x);          // takes an int
    void displayArray();           // displays the total values of all the elements currently in the array
    void deleteLast();             // deletes the last entered value to the array and steps back the position counter
    int numberOfElements();        // returns the current number of elements which is = to the member position. So it returns that member
    int lastValueEntered();        // returns the last value entered
    int highestValue();            // searches for highest value and removes it from the array
    void removeDubs();              // removes duplicates
    bool Empty();                   // tests if the array is empty
    bool Full();                    // tests if the array is full

    virtual ~Array();

    private:
      int MaxSize;
      int position;                 // member used to keep track of the position in the array
      int* unsorted;                // array used to collect values from the user.


};

#endif // ARRAY_H
