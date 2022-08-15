#include<iostream>
#include"constants.h"
#include<cassert>
// * execution path: specific sequemce of statements executed by a program
// * Control flow statements allow to change (branch) execution path
// * danling else: last else is matched up with last free if, easily avoided
//   by always using blocks with conditionals
// * switch statements: selecting between number of matching items (only works
//   with integral types
// * 

double calculateHeight(double initialHeight, int seconds)
{
    double distanceFallen { myConstants::gravity * seconds * seconds / 2 };
    double heightNow { initialHeight - distanceFallen };

    //check whether we've gone under the ground
    // if so, set the height to ground leverl
    if (heightNow <0.0)
    {
        return 0.0;
    }
    else
    {
        return heightNow;
    }
}

void calculateAndPrintHeight(double initialHeight)
{

    int time { 0 };
    double currentHeight{initialHeight};
    while (currentHeight)
    {
        currentHeight = calculateHeight(initialHeight, time);
        std::cout << "At " << time << " seconds, the ball is at height: " 
            << currentHeight << "\n";
    ++time;
    }
}

bool isPrime(int x)
{
    
    if (x < 2)
    {
        return false;
    }
    else
    {
        for (int divider{ 2 }; divider < x; ++divider)
        {
            if (x % divider == 0)
            {
                return false;
            }
        }
        return true;
    }
}

int main()
{
    std::cout << "Enter the intial height of the tower in meters: ";
    double initialHeight {};
    std::cin >> initialHeight;

    calculateAndPrintHeight(initialHeight);

    
    assert(!isPrime(0));
    assert(!isPrime(1));
    assert(isPrime(2));
    assert(isPrime(3));
    assert(!isPrime(4));
    assert(isPrime(5));
    assert(isPrime(7));
    assert(!isPrime(9));
    assert(isPrime(11));
    assert(isPrime(13));
    assert(!isPrime(15));
    assert(!isPrime(16));
    assert(isPrime(17));
    assert(isPrime(19));
    assert(isPrime(97));
    assert(!isPrime(99));
    assert(isPrime(13417));

    std::cout << "Success!\n";


    return 0;
}
