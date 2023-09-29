#include<iostream>
#include <chrono>
#include <random>

/*
15.7 Static member functions

Static member variables are variables that actually belong to the class and not
to any object that was instantiatet of that class.
If they were public they can be accessed by simply using the class name and 
the scope resolution operator.

But this is not possible if they are private, thus we need to declare a member
function to access them.
This member function can also be static to avoid having to first instantiate a
class object before being able to use the member function.

Since static member functions are not attached to a class object, they have no
"*this" pointer.
Therefore they can only access static member variables, since non-static member
variables are always attached to an object and static member functions have no
object to work with.


*/

//Question 1 "Convert Random namespace to a class with static member"
class Random
{
private:	
    static inline std::mt19937 generate()
	{
		std::random_device rd{};

		// Create seed_seq with high-res clock and 7 random numbers from std::random_device
		std::seed_seq ss{
			static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
				rd(), rd(), rd(), rd(), rd(), rd(), rd() };

		return std::mt19937{ ss };
	}

    static inline std::mt19937 mt{ generate() }; // generates a seeded std::mt19937 and copies it into our global object
public:
    
	
	// Generate a random int between [min, max] (inclusive)
	static inline int get(int min, int max)
	{
		return std::uniform_int_distribution{min, max}(mt);
	}
};


class Something {
private:
    static inline int s_value { 1 };
public:
    static int getValue() { return s_value; } // static member function
};



int main() {
    std::cout << Something::getValue() << '\n'; //error

	// Print a bunch of random numbers
	for (int count{ 1 }; count <= 10; ++count)
		std::cout << Random::get(1, 6) << '\t';

	std::cout << '\n';

    return 0;
}