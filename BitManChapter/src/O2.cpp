#include<iostream>
#include<bitset>

// O.2 Bitwise operators
// Operator     |  Symbol  |  Form  |  Operation
// left shift   |    <<    |  x<<y  | all bits in x shifted left by y places
// right shift  |    >>    |  x>>y  | all bits in x shifted right by y places
// bitwise NOT  |    ~     |   ~x   | all bits in x flipped
// bitwise AND  |    &     |   x&y  | each bit in x AND each bit in y
// bitwise OR   |    |     |   x|y  | each bit in x OR each bit in y
// bitwise XOR  |    ^     |   x^y  | each bit in x XOR each bit in y
// 
// /Best Practice/: To avoid surprises, use the bitwise operators with 
// unsigned operands or std::bitset
// 0011 << 1 is 0110, all bits shifted out of the complete number are lost forever
// 0011 >> 1 is 0001

// Bitwise NOT: ~0101 is 1010
// Bitwise  OR: 0101 | 0110 is 0111
// Bitwise AND: 0101 & 0110 is 0100
// Bitwise XOR: 0101 ^ 0110 is 0011

// Every bitwise operator can be used with a "=" operator to facilitate easy
// modifications of variables

std::bitset<4> rotl(std::bitset<4> bits)
{
    std::bitset<4> original{ bits };
    
    bool rotatesOut { original.test(3) };
    original <<= 1;

    if (rotatesOut)
    {
        original = original.set(0);
    } 
    
    return original;
}
// or alternatively:

std::bitset<4> rotL(std::bitset<4> bits)
{
    //my working but complicated written solution
//    std::bitset<4> original{ bits };
//    std::bitset<4> oneLeft{ };
//    std::bitset<4> threeRight{ };
//    oneLeft = (original << 1);
//    threeRight = (original >>3);
//    original = (oneLeft | threeRight);
//    return original;
//
    return (bits<<1) | (bits>>3);
}
int main()
{
    std::bitset<4> x { 0b1100 };

    std::cout << x << '\n';
    std::cout << (x >> 1) << '\n';
    std::cout << (x << 1) << '\n';

    std::bitset<4> bits1 { 0b0001 };
    std::cout << rotl(bits1) << '\n';

    std::bitset<4> bits2 { 0b1001 };
    std::cout << rotl(bits2) << '\n';
   
    
    std::bitset<4> bits3 { 0b0001 };
    std::cout << rotL(bits3) << '\n';

    std::bitset<4> bits4 { 0b1001 };
    std::cout << rotL(bits4) << '\n';
    return 0;
}
