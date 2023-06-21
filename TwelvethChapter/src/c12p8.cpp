#include<iostream>
#include<algorithm>
#include<array>
#include<string>
#include<string_view>



/*
12.8 Lambda captures
lambdas can only access specific kinds of identifiers:
* global identifiers
* entities known at compile time 
* entities with static storage duration

the capture clause can be used to (indirectly) give lambda access to variables
available in the surrounding scope that it normally would not have access to

the captured variabels of a lambda are clones of the outer scope variables, not
the actual variables
these clones are by default "const values", thus, the lambda is not allowed to vary them
it is possible to use the mutable keyword in the lambda definition to make the copy
of the captured variabel changeable, but it will still only change the copy not
the original variable.
but we can also pass objects by reference
below we use passing by reference to count how many comaprisons std::sort makes
when sorting an array
multiple variables can be captured and seperated by comma, this can contain a mix
of variables captured by value or reference

There is a default caputre that automatically catures all the variables that are
mentioned inside the lambda
To capture all used variables an "=" can be used as capture value, if all are supposed
to be captured by reference an "&" can be used as capture value
This can also be mixed (e.g. [&, enemies] captures everything that is mentioned by
reference except for the variable enemies that is captured by value)
Captures also allow to initialize variables inside them without providing a type
"Best practice:" Only intitialize variables in the capture if their value is short
and their type is obvious. Otherwise it is best to define the variabels outside of the
lambda and capture it.!

One must be extra carefull when caputring by reference since it is the programmers
job to ensure that the caputred variable is still alive and the lamda is not left
with a dangling reference

RULE: Standard library functions may copy function objects (reminder: lambdas are 
funtion objects). If you want to provide lambdas with mutable caputred variables,+
pass them by reference using std::ref())
"Best practice:" Try to avoid mutable lambdas. Non-mutable lambdas are easier
to understand and do not suffer from the above issues, as well as more dangerous
issues that arise when you add parallel execution.


*/

struct Car {
    std::string make {};
    std::string model{};
};

int main() {

    std::array<std::string_view, 4> arr { "apple", "banana", "walnut", "lemon" };

    std::cout << "search for: ";

    std::string search{};
    std::cin >> search;

    //Caputre @search
    auto found{ std::find_if(arr.begin(), arr.end(), [search](std::string_view str) {
        return (str.find(search) != std::string_view::npos);
    })};

    if (found == arr.end())
    {
        std::cout << "Not found\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }

    //pass by reference example
    std::array<Car, 3> cars{ {  {"Volkswagen", "Golf"},
                                {"Toyota", "Corolla"},
                                {"Honda", "Civic"}   }};

    int comparisons {0};

    std::sort(cars.begin(), cars.end(),
            //cature @comparisons by referecnce
            [&comparisons](const auto& a, const auto& b) {
                ++comparisons;
                //sort the cars by their make
                return (a.make < b.make);
            });
    std::cout << "Comparisons: " << comparisons << '\n';

    for (const auto& car : cars)
   {
    std::cout << car.make << ' ' << car.model << '\n';
   } 


    return 0;
}