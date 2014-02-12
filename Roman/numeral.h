#ifndef NUMERAL_H
#define NUMERAL_H

#include <string>
using namespace std;
/**
* Filename: numeral.h
* Author: James Narayana Emery
* Date: 4/20/2013
* Purpose: declare methods/members
*/
class Numeral
{
    public:
        Numeral();
        virtual ~Numeral();
        string getroman() { return roman; };
        void setroman(string number);
    protected:
    private:
        string roman;
};

#endif // NUMERAL_H
