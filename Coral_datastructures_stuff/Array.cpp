/**
Author: Corral Breding
title: Array.cpp
content: contains all functions for the prototypes of the array class
**/
#include "Array.h"
#include <iostream>
using namespace std;

// default constructor
// member for stepping through the array
// initializes all of the values in the array to 0
Array::Array()
{
    position = 0;


    unsorted = new int[SIZE];   //dynamic unsorted array

}

//overloaded constructor takes a int and uses its value to set the
// size of the array
Array::Array(int s)
{
    MaxSize = s;
    position = 0;


    unsorted = new int[MaxSize];    //dynamic unsorted array


}

// set Value
// takes an int and sets it to the current position of the array
// after a value has filled an element the position is incremented
void Array::setValue(int y)
{
    if(!Full())
    {
    unsorted[position] = y;
    position ++;
    }

}


// displayArray
// displays all of the values of the array using a for loop
void Array::displayArray()
{

    for(int i=0; i<position; i++)
    {
        cout << unsorted[i] << endl;
    }
}


// deleteLast
// steps back the position counter by 1
// next it sets the last position to 0 to delete the value stored in that element.
void Array::deleteLast()
{

    if(!Empty())
    {
    position--;
    }


}

bool Array::Empty()
{
    if(position == 0)   // if array is empty
    {
        cout << "Can not remove values - array is Empty" << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}

bool Array::Full()
{
    if(position == MaxSize)
    {
        cout << "Can not insert values - array is full " << endl;
        return 1;
    }
    else
    {
        return 0;
    }
}


//numberOfElements
//this function returns the position member, since its value is = to the number of elements currently stored in the array
int Array::numberOfElements()
{
   return position;
}

//lastValueEntered
// this function returns the last value entered
int Array::lastValueEntered()
{
    return unsorted[position - 1];
}

//highestValue
// this function returns the highest value from the array then removes it from the array
char Array::highestValue()
{
        if(Empty())
        {
            int temp = unsorted[0];
            int tempPosition;
            for(int i = 0; i < position; i++)
               {
                   if(temp < unsorted[i])       // finding the highest value
                   {
                      temp = unsorted[i];
                      tempPosition = i;
                   }
               }
                      for(int x = tempPosition; x < position-1; x++)
                        {
                            unsorted[x] = unsorted[x+1];
                        }
                    position--;


               return temp;
        }
    }


//sortHightoLow
// this function uses a bubble sorting method. It checks the value stored
// next to the current element and if it is greater it switches them.

//removeDubs
// removes all duplicates from the array
void Array::removeDubs()
{
    for(int i = 0; i < position; i++)
    {
        for(int j = i+1; j < position; j++)
        {
            if(unsorted[i] == unsorted[j])
            {
                for(int x = i; x < position; x++)
                {
                    unsorted[x] = unsorted[x+1];
                }
                position--;
            }
        }
    }
}
// destructor
 Array::~Array()
 {
    delete [] unsorted;

 }






