/***************************
** Created by Nathan Healea
** Date Created :
** Date Last Edited:

** file name:

** Memo:

****************************/

#ifndef CALULATOR_H
#define CALULATOR_H


class Calulator
{
    public:
        Calulator();
        int getFistnum() { return firstNum; }
        int getSecondNum() { return secondNum; }
        void setFirstNum(int numOne) {firstNum = numOne; }
        void setSecondNum(int numTwo) { secondNum = numTwo; }
        int Add();
        int Subtract();
        int Multiply();
        float Divide();
        virtual ~Calulator();
    protected:
    private:
        int firstNum;
        int secondNum;
};

#endif // CALULATOR_H
