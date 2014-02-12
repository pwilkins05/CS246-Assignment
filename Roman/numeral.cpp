#include "numeral.h"
/**
* Filename: numeral.cpp
* Author: James Narayana Emery
* Date: 4/20/2013
* Purpose: define setroman
*/
Numeral::Numeral()
{
    //ctor
}

Numeral::~Numeral()
{
    //dtor
}

void Numeral::setroman(string number)
{
    roman += number;
}
