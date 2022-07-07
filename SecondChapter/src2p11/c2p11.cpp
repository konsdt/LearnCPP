#include "add.h" // local headers first and with double quotes

#include <iostream>

// 2.11 Header files
// Allow to put forward declarations in one file and then import them when
// needed. This saves a lot of typing.
// Best practice:
// header files only contain forward declarations, the definition is part of a
// seperate source .cpp file (To not violate one definition rule)
// In case of iostream this would be in the standard cpp library that is 
// automatically linked to my program
//
// a header file consists of two parts:
// 1. header guard
// 2. actual content (forward declarations)
//
// Best practice: Use .h suffix for header files
// Best practice: Header files are paired with code files and should have the
// same base name (e.g: add.cpp and add.h)
// 
// Header files commonly need declararions from other header files,
// therefore they will include other header files often -> these will be included
// "transitively" in the cpp file aswell and are useable, but do not rely on that!
// Best practice: Every file should include all header file it needs to compile
// explicitly! Dont use transitivily included header files
//
// Best practice ordering header files:
// 1. Paired header file
// 2. Other headers from your project
// 3. 3rd party headers
// 4. Standard library headers
// Each group should be sorted alphabetically!
//
// 2.12 Header guards
// Header guards are needed to not violate the one definition rule frequently
// This can easily happen in bigger projects since header files will often include
// other header files that might already include header files that are then 
// included twice...
// Thus we need header guards -> see add.h

int main()
{
    std::cout << "The sum of 3 and 4 is " << add(3, 4) << "\n";
    return 0;
}
