#include<iostream>
#include<bitset>

// O.1 Bit flags and bit manipulation via std::bitset
// Every object has to have a unique address in memory. Since only every byte
// has its own address any object per default at least takes up the space of 
// 8 bits (1 byte). Usually this is fine but in case of a bool this takes up
// way too much memory (7 bits too many)
// C++ allows to manipulate objects at bit level (usefull in memory sensitive 
// cases)
// "Bit flags":
// we can view objects as holding a collection of bits, when individual bits of
// an objct are used as Boolen values, the bits are called "bit flags"
// In computing: a flag is a value that acts as a signal for some function process.
// To define a set of bitflags, typically an unsigned integer of the appropriate
// size is used, or std::bitset which comes in the bitset header
// /Best practice/: Bit manipulation is one of the times you should only use 
// unsigned integers.
// Using std::bitset is the easy way, but the less versatile way.
// given a byte the bits are numbered from RIGHT to LEFT starting with 0
// 76543210 Bit Postion
// 00000101 Bit Sequence
// std::bitset provides 4 key functions:
// test() allows to test wether a specfic bit is a 0 or a 1
// set() turns a bit on (to one), does nothing if its already on
// reset() turns bit off (to zero), does nothing if its already off
// flip() allows us to flip a bit value from a 0 to a 1 or vice versa
// 0b is the binary prefix (') can be used as digit seperator which makes it 
// a lot easier to read
// 
// bitset does not have easy possibilities to get or set multiple integers
// at once -> use the unsigned integers
int main()
{
    std::bitset<8> bits {0b0000'0101}; 

    bits.set(3);   // set bit position 3 to 1 (now we have 0000'1101)
    bits.flip(4);  // flip bit 4 (now we have 0001'1101)
    bits.reset(4); // set bit 4 back to 0 (now we have 0000'1101)
    
    std::cout << "All the bits: " << bits << '\n';
    std::cout << "Bit 3 has value: " << bits.test(3) << '\n';
    std::cout << "Bit 4 has value: " << bits.test(4) << '\n';

    return 0;
}
