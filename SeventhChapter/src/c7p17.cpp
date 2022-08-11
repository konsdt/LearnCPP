#include<cmath>
#include<cassert>
#include<random>
#include<chrono>
#include<iostream>
// 7.17 Assert and static_assert
// An "assertion" is an expression that will be true unless there is a bug in the
// program. If the expression is false the program will display an error message
// and terminate the execution of the program with std::abort
// runtime assertions are implemented via the assert preprocessor macro which 
// lives in the <cassert> header
// assert can be used everywhere one wants to evaluate that somethin is true
// asserts are one of the only preprocessor macros one is encouraged to use
// "Asserts vs error handling":
// asserts document cases that shoud logically neve be allowed to happen!
// therfore one can not recover from them
// error handling is designed to gracefully handle cases that could happen, and
// one should always assume that the user of the program might encounter them 
// /Best Practice/: Use assertions to document cases that should be logically
// impossible.
// asserts come with performance costs and should therefore only be active in
// debug builds ->NDEBUG macro to disable the asserts
// "static_assert": compile time assertion static_assert(condition, diagnostic_message)
//
// 7.18 Introduction to random number generation
// "Algorithms and state"
// an algorithm is a finite sequence of instructions that can be followed to solve
// a problem or produce some useful result
// it is considered "stateful" if it retains some information across calls, if4
// it does not retain any information it is considered "stateless"
// the "state" refers to the current values held in the stateful variables
// "deterministic": for a given input the algorithm will always produce the same
// output
// "Pseudo random number generators (PRNGs)
// all its random numbers are deterministically calculated from the seed value
// * should produce uniformly distributed random numbers
// * should not be predictable
// * should be efficient
// Best PRNG that ships with c++20 in the header <random> is mersenne twister
// still this is outdated in the meanwhile and usually one should use 3rd party
// libraries, most popular:
// 1. Xoshiro family and Wyrand for non-cryptographic PRNGs
// 2. Chacha family for cryptographic (non-predictable) PRNGs
//
// 7.19 Generating random numbers with mersenne twister:
// std::mt19937 generates 32-bit unssigned integers
// std::mt19937_64 generates 64-bit unssigned integers
// "seeding with the system clock": as done below,
// std::chrono::high_resolution_clock is also a very popular choice for doing this,
// it is the most granular, but it uses the system clock and therefore can be 
// influenced by the user,
// std::chrono::steady_clock has a less granular tick time but is the only clock
// with a guarantee that users can not adjust it
// "Seeding with random device":
// /Best Practice/: Use std::random_device to seed your PRNGs except if its not
// properly implemented for your target compiler/architecture.
// /Best Practice/: Only seed a given PRNG once, and do not reseed it!
// That means do not initialize the seed in the function you call to perform
// the entire random action, otherwise it will be reseeded every time the 
// function is called
// The best way to do it is to create a global random number generator inside
// a namespace and therefore also a global seed.
// This is an exception of the rule to avoid non-const global variables.#

namespace Random // captial R to avid conflicts with functions named random()
{
    std::mt19937 mt { std::random_device{}() };

    int get( int min, int max )
    { 
        std::uniform_int_distribution die{ min, max };
        return die(mt);

    }
}

double calculateTimeUntilObjectHitsGround(double initialHeight, double gravity)
{
    assert(gravity > 0.0 && "Gravity can not be smaller or equal to zero, since otherwise the object will not reach the ground"); // The object wont reach the ground unless there is
                           // a positive gravity
    if (initialHeight <= 0.0)
    {
        // The object is already on the ground. Or buried.
        return 0.0;
    }

    return std::sqrt((2.0 * initialHeight) / gravity );
}


int main()
{
    
    std::cout << "Took " << calculateTimeUntilObjectHitsGround(100.0, 9.8) << " second(s)\n";
    

    // Seed our Mersenne Twister using the
    std::mt19937 mt{ static_cast<unsigned int>(
            std::chrono::steady_clock::now().time_since_epoch().count()
            ) };
    
    std::mt19937 mt2 { std::random_device{}() };

    // Create a reusable random number generator that generates unifrom numbers 
    // between 1 and 6
    std::uniform_int_distribution die6{ 1, 6 };

    // Print a bunch of random numbers
    for (int count{ 1 }; count <= 40; ++count)
    {
        std::cout << die6(mt) << '\t'; // generate a roll of the die here
                                       //
        // IF we've printed 10 numbers, start a new row
        if (count % 10 == 0)
            std::cout << '\n';
    }
    

    std::cout << Random::get(1, 6) << '\n';
    std::cout << Random::get(1, 10) << '\n';
    std::cout << Random::get(1, 20) << '\n';



    return 0;
}
