#include <iostream>
#include <cmath>

/// Created by Duncan M. Luiten
double Get_Sharpness_Damage(int sharp, int RESsharp);
double Get_Crit(int critical);
double Get_Block(int block);

int main()
{

 /// This is a rough draft for a damage formula that I just made up
 /// We want to enter numbers for specific stats and make sure that we are getting out the correct values.
 /// you can use a calculator to test this stuff if you want.

 ///*******************************************************************************************************************
 /// Things to fix
 ///
 /// #1. The stats currently don't check for wrong values. Put in error detectors.
 /// #2. create a small element effect system. Example: like a precent multiplier for the damage formula.
 /// #3. make it so critical and block give small addition bonuses as well as the multiplication effect.
 ///
 ///*******************************************************************************************************************

 /// use values of around 300 for attack and defense.

 int attack = 0;
 int defense = 0;
 int sharpness = 1; /// seven levels of sharpness
 int critical = 0; /// two levels of critacl;
 int block = 0; /// two levels of block
 int RESsharpness = 1; /// seven levels of sharpness resistance.
 int element = 0;

 double totalPE;
 double totalEP;

 std::cout << "insert attack value\n";
 std::cin >> attack;
 std::cout << "insert defense value\n";
 std::cin >> defense;
 std::cout << "insert sharpness value (1 = red, 2 = orange, 3 = yellow, 4 = green, 5 = blue, 6 = white, 7 = purple, 8 = hyper)\n";
 std::cin >> sharpness;
 std::cout << "insert RESsharpness value (1 = red, 2 = orange, 3 = yellow, 4 = green, 5 = blue, 6 = white, 7 = purple, 8 = hyper)\n";
 std::cin >> RESsharpness;
 std::cout << "insert critical value (0 = none, 1 = critical, 2 = master-critical)\n";
 std::cin >> critical;
 std::cout << "insert block value (0 = none, 1 = block, 2 = perfect-block)\n";
 std::cin >> block;
 std::cout << "insert element (0 = normal, 1 = fire, 2 = water, 3 = lightning, 4 = dark, 5 = light)\n";
 std::cin >> element;

// If Player attacking an Enemy

totalPE = ((attack - defense) * 0.25) + (((attack * Get_Sharpness_Damage(sharpness, RESsharpness) * Get_Crit(critical)) - (defense * Get_Block(block))) * 0.45);

if (totalPE < 0){totalPE = 0;}

// If enemy attacking a Player

totalEP = ((attack - defense) * 0.25) + (((attack * Get_Crit(critical)) - (defense * Get_Block(block))) * 0.45);

if (totalEP < 0){totalEP = 0;}

std::cout << "\n\n\nPlayer Damage : " << totalPE;
std::cout << "\n\n\nEnemy Damage : " << totalEP;

// print out both numbers.
// players and enemys shall have different HP depending on this effect.
// there could be large discrepancys with the damage

}

double Get_Sharpness_Damage(int sharp, int RESsharp)
{

double temp = 0;
double temp2 = 0;

temp = sharp - RESsharp;

temp2 = ((double)sharp / 12);

if (temp > 0)
    {
        temp = temp2 + 1;
    }
else if (temp == 0)
    {
        temp = temp2 + 0.25;
    }
else
    {
        temp = 0.1;
    }

return temp;

}

double Get_Crit(int critical)
{

if(critical == 0){return 1;}
if(critical == 1){return 1.2;}
if(critical == 2){return 1.6;}

return 1;
}

double Get_Block(int block)
{

if(block == 0){return 1;}
if(block == 0){return 0.88;}
if(block == 0){return 0.50;}

return 1;
}
