#include <iostream>

#define PROJECT_NAME "ArraysStringsAndDynamicAllocation"

// 11.1 Arrays (Part 1)
// In an array variable declaration we use square brackets to tell the compiler
// both that this is an array variable as well as how many variables to allocate
// C++ arrays start to count from 0
// The range of an array with length N would be from 0 to N-1
// Array can be made from any data type, they can also be made from structs
//
// Arrray subscripts must always be integral type, this includes char, short,
// int, long, long long, etc. and weirdly also boolean where false gives an index
// of 0 and true gives an index of 1
//
// When declaring a fixed array, the length of the array must be a compile time 
// constant. therefore non-const variables or runtime constants cannot be used
// 
// Fixed arrays come with some limitations:
// 1. Fixed arrays cannot have a length based on either user input or some other
// value calculated at runtime
// 2. Fixed arrays have a fixed length that can not be changed
//
// C++ therefore also supports dynamic arrays. Those are a bit more complicated
// to instantiate therefore they will be covered later during this chapter. 


int main() 
{
    // different ok ways to define an array:
    int numberofLessonsPerDay[7]{};

    constexpr int daysPerWeek { 7 };
    int numberofLessonsPerDay1[daysPerWeek]{};

    enum DaysOfWeek
    {
        monday,
        tuesday,
        wednesday,
        thursday,
        friday,
        sunday,

        maxDaysOfWeek
    };
    
    int numberofLessonsPerDay2[maxDaysOfWeek]{};
    
    //using a macro
    
    #define DAYS_PER_WEEK 7
    int numberofLessonsPerDay3[DAYS_PER_WEEK]{};

    struct Rectangle
    {
        int length {};
        int width {};
    };
    Rectangle rects[5]{};
    // this can be accessed by first picking the array element and then use the 
    // member selection operator
    rects[0].length = 24;


    int prime[5]{}; // hold the first 5 prime numbers
    prime[0] = 2;
    prime[1] = 3;
    prime[2] = 5;
    prime[3] = 7;
    prime[4] = 11; // The last element has index 4 (array length-1)
                   //

    std::cout << "The lowest prime number is: " << prime[0] << '\n';
    std::cout << "The sum of the first 5 prime numbers is: " << 
        prime[0] + prime[1] + prime[2] + prime[3] + prime[4] << "\n";

    return 0;
}
