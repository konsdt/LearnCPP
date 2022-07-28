#include<iostream>
#include<cstdint>
#include<bitset>

// O.3 Bit manipulation with bitwise operators and bit masks
// "Bit masks":
// bitwise operators do not know how to work with bit positions,
// a bitmask is a predefined set of bits that is used to select which specific
// bit will be manipulated by the following operations
// Thes bit masks will be predefined for use later
// after c++14 they can be defined with uint_8 constexpr using binary literals
// meaning: e.g.: 0b0000'0001
// Before that hexadecimal had to be used
// 0        0000
// 1        0001
// 2        0010
// 3        0011
// 4        0100
// 5        0101
// 6        0110
// 7        0111
// 8        1000
// 9        1001
// A        1010
// B        1011
// C        1100
// D        1101
// E        1110
// F        1111
//
// one could also define a 1 and shift it with the binary operator
int main()
{

    constexpr std::uint8_t mask0 { 0x01 };
    constexpr std::uint8_t mask1 { 0x02 };
    constexpr std::uint8_t mask2 { 0x03 };
    constexpr std::uint8_t mask3 { 0x08 };
    constexpr std::uint8_t mask4 { 0x10 };
    constexpr std::uint8_t mask5 { 0x20 };
    constexpr std::uint8_t mask6 { 0x30 };
    constexpr std::uint8_t mask7 { 0x80 };
    
    // Testing a bit to see of it is on or off:
    std::uint8_t flags{ 0b0000'0101 };

    std::cout << "bit 0 is " << ((mask0 & flags) ? "on.\n" : "off.\n");
    std::cout << "bit 1 is " << ((mask1 & flags) ? "on.\n" : "off.\n");

    //Setting a bit, use |=
    flags |= mask1;
    std::cout << "bit 1 is " << ((mask1 & flags) ? "on.\n" : "off.\n");
 
    //Resetting a bit, use 
    flags &= ~mask1,
    std::cout << "bit 1 is " << ((mask1 & flags) ? "on.\n" : "off.\n");
    
    // Both works with multiple bits at the same time
    // e.g. flags |= (mask4 | mask7);
    // e.g. flags &= ~(mask4 | mask7);

    //Toggle/flip a bit is done with the xor operator:
    flags ^= mask1;
    std::cout << "bit 1 is " << ((mask1 & flags) ? "on.\n" : "off.\n");
    flags ^= mask1;
    std::cout << "bit 1 is " << ((mask1 & flags) ? "on.\n" : "off.\n");
    
    // Bit flags get usefull when we do not call the individual masks "masks"
    // but instead give them the meaning the bool represents e.g. isHappy{ 0x01 };
    // also especially usefull if one has extremely many similar objects we want
    // to save properties of
    // Or in a function that e.g. take 32 bools as input. This also safes a lot
    // of typing and space
    // Also very helpfull in extracting color coding of a screen (RGB,A) where A
    // stands for alpha and controls how transparent or opaque the pixel should be
    //
    constexpr std::uint32_t redBits { 0xFF000000 };
    constexpr std::uint32_t greenBits { 0x00FF0000 };
    constexpr std::uint32_t blueBits { 0x0000FF00 };
    constexpr std::uint32_t alphaBits { 0x000000FF };

    // Every color value is saved as a byte (8bits)

    std::cout << "Enter a 32-bit RGBA color value in hexadecimal (e.g.FF7F3300): ";
    std::uint32_t pixel{};
    std::cin >> std::hex >> pixel; //std::hex allows to read in a hex value
    
    // use bitwise AND to isolate the pixels.
    std::uint8_t red { static_cast<uint8_t>((pixel & redBits) >> 24) };
    std::uint8_t green { static_cast<uint8_t>((pixel & greenBits) >> 16) };
    std::uint8_t blue { static_cast<uint8_t>((pixel & blueBits) >> 8) };
    std::uint8_t alpha { static_cast<uint8_t>((pixel & alphaBits)) };
    
    std::cout << "Your color contains:\n";
    std::cout << std::hex;
    std::cout << static_cast<int>(red) << " red\n";
    std::cout << static_cast<int>(green) << " green\n";
    std::cout << static_cast<int>(blue) << " blue\n";
    std::cout << static_cast<int>(alpha) << " alpha\n";

    constexpr std::uint8_t option_viewed{ 0x01 };
    constexpr std::uint8_t option_edited{ 0x02 };
    constexpr std::uint8_t option_favorited{ 0x04 };
    constexpr std::uint8_t option_shared{ 0x08 };
    constexpr std::uint8_t option_deleted{ 0x10 };

    std::uint8_t myArticleFlags { option_favorited };

    myArticleFlags |= option_viewed;
    
    if (myArticleFlags & option_deleted)
        std::cout << "Article was deleted.\n";

    myArticleFlags &= ~option_favorited;

    std::cout << std::bitset<8>{ myArticleFlags  } << '\n';

    return 0;
}
