#include<iostream>
#include<bitset>
#include<cstdint>

// O.4 Coverting between binary and decimal
// Converting is pretty easy if you now the rules:
// decimal is called decimal because the following is true:
// 5562 = (5 * 1000) + (5 * 100) + (6* 10) + (2 * 1)
//
// in binary you dont go up in steps of times 10 but in steps of times two:
// 1000'1010 = (1 * 128) + (0 * 64) + (0 * 32) + (0 * 16) + (1 * 8) + (0 * 4) + (1 * 2) + (0 * 1) = 138
//
// "Adding in binary:"
//  number 6: 0110
//  number 7: 0111
//  ----------------
//            1101   
// pretty simple: 
// line them up start from the right go to the left and follow these rules:
// 0 + 0 = 0
// 1 + 0 = 1
// 0 + 1 = 1
// 1 + 1 = 0 And carry a one to the next column
//
// Signed numbers: have one bit (leftmost or most significant bit) that stores
// the sign. Negative sign bits are stored as the bitwise inverse of the positive
// number, plus 1.
// Therefore negative five (-5) looks like this:
// Positive representation of 5: 0000'0101
// Then invert every bit: 1111'1010
// Then add 1: 1111'1011.
// Tada negative five..
//
// Convert -76:
// Positive: 0100'1100
// Inverted: 1011'0011
// plus 1:   1011'0100
//
// One is added to avoid having different representations for +0 and -0
// +0 would be 0000'0000
// Inverting:  1111'1111
// plus 1:     0000'0000 Overflows and leads to same representation
//
// QUIZTIME:
//
// 0100'1101 = 64+8+4+1 = 77
//
// Convert 93 to an unsigned binary number with both possible methods:
// First Method:
// 93/2 = 46 r1
// 46/2 = 23 r0
// 23/2 = 11 r1
// 11/2 = 5 r1
// 5/2 = 2 r1
// 2/2 = 1 r0
// 1/2 = 0 r1
//
// construct the binary from the bottom up : 0101'1101
// Second Method:
// 93 >=128 False
// 93 >=64 True 93 - 64 = 29
// 29 >=32 False
// 29 >=16 True 29 - 16 = 13
// 13 >= 8 True 13 - 8 = 5
// 5 >= 4 True 5 - 4 = 1
// 1 >= 2 False
// 1 >= 1 True 1 - = 0
//
// For every True a 1:  0101'1101
//
// Convert -93
// Positive 93: 0101'1101
// Invert: 1010'0010
// Plus 1: 1010'0011
//
// Convert 1010 0010 to an unsigned decimal number:
// 128 + 32 + 2 = 162
//
//
//


int printAndDecrementOne(int userInput, int powerOfTwo)
{
    std::cout << '1';
    return (userInput - powerOfTwo);
}
int printAndDecrementBit(int userInput, int powerOfTwo)
{
    if (userInput >= powerOfTwo)
        return printAndDecrementOne(userInput, powerOfTwo);

    std::cout << '0';
    return userInput;
}
int main()
{
    
    int userInput {};
    std::cout << "Please enter an integer between 0 and 255: ";
    std::cin >> userInput;
    
    userInput = printAndDecrementBit(userInput, 128);
    userInput = printAndDecrementBit(userInput, 64);
    userInput = printAndDecrementBit(userInput, 32);
    userInput = printAndDecrementBit(userInput, 16);
    userInput = printAndDecrementBit(userInput, 8);
    userInput = printAndDecrementBit(userInput, 4);
    userInput = printAndDecrementBit(userInput, 2);
    userInput = printAndDecrementBit(userInput, 1);
    return 0;
}
