/**
Author: Corral Breding
title: main.cpp
content: Contains drivers for the array class
**/


#include "Array.h"
#include <iostream>

using namespace std;

int main()
{
    /**         Problem 1       **/

    Array unsorted(5);


    cout << "Creating an Array of size 5:\n " << endl;
    cout << "Sending in 5 values: " << endl;

    // adding in 5 values.
    unsorted.setValue(5);
    unsorted.setValue(1);
    unsorted.setValue(75);
    unsorted.setValue(16);
    unsorted.setValue(15);
    cout << "Sending in two more values to try and overfill the array" << endl;
    // try to overfill the array
    unsorted.setValue(16);
    unsorted.setValue(15);                  // no UI out to warn, but it does not allow additional items in

    cout << "\nThe current number of elements are: " << unsorted.numberOfElements() << endl;          // geting the number of elements stored in the array
    cout << "Those values are " << endl;
    unsorted.displayArray();                                // display the array


    cout << "Deleting the last element: " << endl;
    unsorted.deleteLast();                                  // delete last element
    unsorted.displayArray();                                // display the list with the delted value

    cout << "Removing all values to check the empty boundry: " << endl;
    unsorted.deleteLast();unsorted.deleteLast();unsorted.deleteLast();unsorted.deleteLast();unsorted.deleteLast();

    //showing that all vlaues have been removed
    cout <<"\nArrays values are: " << endl;
    unsorted.displayArray();    //passed


    /**         Problem 2       **/

    // refilling the array with one duplicate and displaying its new content
    cout << "\n\nRefilling the array: " << endl;
    unsorted.setValue(5);
    unsorted.setValue(1);
    unsorted.setValue(5);
    unsorted.setValue(16);
    unsorted.setValue(15);

    cout << "Values in the array are: " << endl;
    unsorted.displayArray();

    // using the highestValue function to remove the highest value from the array
    cout << "Pulling out the highest value: " << unsorted.highestValue() << endl;
    unsorted.displayArray();

    // pulling out two more high values
    cout << "Pulling out 2 more High Values.\nHigh Value #1 = " << unsorted.highestValue() << endl;
    cout << "High Value #2 = " << unsorted.highestValue() << endl;

    //displaying remainging values
    cout << "\n\nRemaing values are: " << endl;
    unsorted.displayArray();


                /**         Problem 3       **/


    // refilling the array with a duplicate
    cout << "Refilling the Array:" << endl;
    unsorted.setValue(5);
    unsorted.setValue(10);
    unsorted.setValue(9);


    //displaying the values in the array
    cout << "\nValues in the array are: " << endl;
    unsorted.displayArray();

    //removing duplicates
    cout << "\nRemoving duplicates: " << endl;
    unsorted.removeDubs();
    unsorted.displayArray();        // shows dubs removed


            /**     Problem 4       **/

    Array sorted(5);    //creating second array

    //refilling first array

    cout << "\n\nRefilling the first array with unordered integers:" <<endl;
    unsorted.setValue(2);
    cout << "The values in the array before they are sorte from highest to lowest are: " << endl;
    unsorted.displayArray();

    /** Using the highestValue function to fill the new array from highest to lowest**/

    while(!unsorted.Empty())
    {
    sorted.setValue(unsorted.highestValue());
    }



    //displaying the values sorted
    cout << "The new arrays values are: " << endl;
    sorted.displayArray();





    return 0;
}
