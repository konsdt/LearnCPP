#include<iostream>
#include<array>
#include<algorithm>
#include<string_view>
#include<functional>
#include<string>

/*
12.7 Introduction to lambdas (anonymous functions)

anonymous function that can be defined in other functions (nested)

syntax:

[ captureClause ] ( parameters ) -> returnType
{
    statements;
}

 * captureClause can be empty if not needed
 * parameter list can be empty if not needed/ also omitted entirely
   if no return type is specified
 * return type is optional and auto is assumed if it is omitted

"Best practice:" Lambdas are preferred over normal functions whenever, trivial,
one-off function to pass as an argument to some other functions are needed!

Defining a lambda right where it is needed is sometimes called a "function literal"

apparently one can store these fake functions in variables with names that 
tell you what the function actually does, ofc this does not safe typing a lot
still you can define a function inside a function like this, also because lambdas
are not really functions at all
They are functors, which allows them to be nested in the first place

"Best practice:" When storing a lambda in a variable, use auto as the variables
type. When passing a lambda to a function:
 * If c++20 capable, use auto as the parameter
 * otherwise, use std::function (pointer)



*/
struct Student{
    std::string name{};
    int points{};
};

struct Season
{
  std::string_view name{};
  double averageTemperature{};
};


int main() {

    constexpr std::array<std::string_view, 4> arr{ "apple", "banana", "walnut",
    "lemon"};

    //Define the function right where it is used

    //Define the lambda in a variable:
    auto containsNut {
        [] (std::string_view str) {
            return (str.find("nut") != std::string_view::npos);
        }
    };

    // a regular function pointer (must have empty capture clause):
    double (*addNumbers1)(double, double){
        [](double a, double b) {
            return (a + b);
        }
    };

    addNumbers1(1, 2);

    // Using std::function. The lambda could have a non-empty capture clause:
    std::function addNumbers2{ // note: pre-C++17, use std::function<double(double, double)>
         [](double a, double b) {
            return (a + b);
        }
    };

    addNumbers2(3, 4);
    


    //Generic Lambdas: When used in context of a lambda "auto" is just a shorthand
    //for a template parameter

    constexpr std::array months{
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };
    // lambda passed here needs to have this signature bool pred(const Type1 &a, const Type2 &b);
    const auto sameLetter{ std::adjacent_find(months.begin(), months.end(),
                                        [](const auto& a, const auto& b) {
                                            return (a[0] == b [0]);
                                        } )};
    // Make sure that two months were found:
    if (sameLetter != months.end())
    {
        // std::next returns the next iterator after sameLetter
        std::cout << *sameLetter << " and " << *std::next(sameLetter)
                  << " start with the same letter.\n";
    }
    // for this case the auto type would not have been a good idea since it would
    // have inferred a c-style string (const char*) these are not easy to work with
    const auto fiveLetterMonths{ std::count_if(months.begin(), months.end(),
                                        [](std::string_view str) {
                                            return (str.length() == 5);
                                        }) };


    std::cout << "There are " << fiveLetterMonths << " months with 5 letters\n";


    // A unique lamda will be created for every different type that auto resolves to:

    auto print{
        [](auto value) {
            static int callCount{ 0 };
            std::cout << callCount++ << ": " << value << '\n';
        }
    };

    print("Hello"); //call count 0
    print("world"); // call count 1

    print(1); // call count 0
    print(2); // call count 1

    // this can become a problem whenever a generic lambda wants to use static
    //duration variables which are not shared between the unique lambdas
    //when returning different types one needs to do one of two things:
    //1. Do explicit conversion so all return types match
    //2. explicitly specifiy a return type for the lambda, and let the compiler 
    //do the implicit conversions
    //ususally 2 is the better choice
    auto divide{ [](int x, int y, bool intDivision) -> double {
        if (intDivision)
            return x / y; // will do an implicit conversion of result to double
        else
            return static_cast<double>(x) / y;
    }};
    
    std::cout << divide(2,3, true) << '\n';
    std::cout << divide(2,3, false) << '\n';

    //Standard library function objects
    // for a lot of straight forward situations we do not really need to write
    // our own lamdas but instead we can use lamdas from the standard library
    // e.g. std::greater{} ({} are needed for instantiation)

    const auto found{ std::find_if(arr.begin(), arr.end(), containsNut) };
    if (found == arr.end())
    {
        std::cout << "No nuts\n";
    }
    else
    {
        std::cout << "Found " << *found << '\n';
    }
    

    //Quiz time
    //1



    const std::array<Student, 8> arr1{
        { { "Albert", 3 },
        { "Ben", 5 },
        { "Christine", 2 },
        { "Dan", 8 },
        { "Enchilada", 4 },
        { "Francis", 1 },
        { "Greg", 3 },
        { "Hagrid", 5 } }
    };

    const auto best{
        std::max_element(arr1.begin(), arr1.end(), [](const auto& a, const auto& b) {
        return (a.points < b.points);
        })
    };

    std::cout << best->name << " is the best student\n";

    //2 
    std::array<Season, 4> seasons{
        { { "Spring", 285.0 },
        { "Summer", 296.0 },
        { "Fall", 288.0 },
        { "Winter", 263.0 } }
    };

    std::sort(seasons.begin(), seasons.end(), 
                [](const auto& a, const auto& b)->bool {
                    return (a.averageTemperature < b.averageTemperature);
                });

    for (const auto& season : seasons)
    {
        std::cout << season.name << '\n';
    }



    return 0;
}