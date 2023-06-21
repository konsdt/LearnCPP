#include<iostream>
#include<algorithm>
#include<vector>
#include<random>


// well yes I solved it, but not as nicely as the solution did,
// I simply spaghetti coded it down and did not package everything up
// nicely into functions
// but at least I did the part with the lambda right xD
// definitely an interesting solution to look at when it comes to code structuring
// config struct etc



int main() {

    std::mt19937 mt{ std::random_device{}() };

	// Create a reusable random number generator that generates uniform numbers between 1 and 6
	std::uniform_int_distribution rand_int{ 2, 4 }; // for C++14, use std::uniform_int_distribution<> die6{ 1, 6 };
    const int factor { rand_int(mt) };

    int start {};
    std::cout << "Start where? ";
    std::cin >> start;

    int count {};
    std::cout << "How many? ";
    std::cin >> count;

    std::vector<int> numbers{ };
    numbers.resize(count);

    for (int i {0}; i < count; i++)
    {
        numbers[i] = start * start * factor;
        ++start;
    }

    std::cout << '\n';
    std::cout << "I generated " << count << " square numbers. Do you know what"
    << " each number is after multiplying it by " << factor << "?" << '\n';

    int search {};

    for (int i {0}; i < count; i++)
    {   
        std::cin >> search;  
        auto found { std::find(numbers.begin(), numbers.end(), search) };  
        if (found != std::end(numbers)) {
            numbers.erase(found);
            std::cout << "Nice " << numbers.size() << " numbers left." << '\n';
        }
        else {
            std::cout << search  << " is wrong. ";
            auto closest { std::min_element(numbers.begin(), numbers.end(), 
                                [=](const auto& a, const auto& b) {
                                    return ( std::abs(a - search) < std::abs(b - search));
                                }) };

            if (*closest - search <= 4) {
                std::cout << "Try " << *closest << " next time";
            }

            break;
        } 
    }

    return 0;
}