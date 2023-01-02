#include <iostream>


// 10.8 Struct passing and miscellany
// structs can be passed as one to a function
// they are generally passed by (const) references to avoid having to make a copy
//
struct Employee
{
    int id {};
    int age {};
    double wage {};
};

void printEmployee(const Employee& employee) // note pass by reference here
{
    std::cout << "ID: " << employee.id << "\n";
    std::cout << "Age: " << employee.age << "\n";
    std::cout << "Wage: " << employee.wage << "\n";
}

struct Point3d
{
    double x { 0 };
    double y { 0 };
    double z { 0 };
};


//Structs are usually returned by value, so as not to return a possibly dangling
//reference.

Point3d getZeroPoint()
{
    // We can create a variable and return the variable 
    Point3d temp { 0.0, 0.0, 0.0 };
    return temp;
};


// Structs can have other user defined members
// Even though in this case Employee is not defined inside the struct company
// it might aswell be since it would still be ok to nest it inside like below
struct Company
{
    int numberOfEmployees {};
    Employee CEO {};
};

// The size of a struct is at least as large as the sum of the sizes of all 
// its members, but it can sometimes be larger due to the compiler adding so called
// padding between the elements to optimize the data structure alignment

struct Foo1
{
    short a {};
    short qq {};
    int b {};
    double c {};
};

struct Foo2
{
    short a {};
    int b {};
    double c {};
    short qq {};
};

// Question 1


struct Advertising
{
    int adsShown {};
    double percentAdsClickedOn {};
    double averageRevenuePerAd {};
};



void printDataAndCalculateTotalRevenue(const Advertising& advertising)
{
    std::cout << advertising.adsShown << " ads were shown today.\n";
    std::cout << advertising.percentAdsClickedOn * 100 << "% of the shown ads were clicked.\n";
    std::cout << "On average " << advertising.averageRevenuePerAd << "$ were earned per click.\n";

    double totalRevenue { advertising.adsShown * advertising.percentAdsClickedOn * advertising.averageRevenuePerAd };

    std::cout << "Today a total of " << totalRevenue << "$ was earned.\n";
};

// Question 2
//

struct Fraction
{
    int numerator {};
    int denominator {};
};

Fraction getFraction()
{
    Fraction fraction {};
    std::cout << "Enter a value for the numerator: ";
    std::cin >> fraction.numerator;
    std::cout << "Enter a value for the denominator: ";
    std::cin >> fraction.denominator;
    std::cout << "\n";
    return fraction;
}

Fraction multiplyFractions(const Fraction& f1, const Fraction& f2)
{
    return { f1.numerator * f2.numerator, f1.denominator * f2.denominator };
}

void printFraction(const Fraction& f)
{
    std::cout << "Your fraction multiplied together: " << f.numerator << "/" << f.denominator << "\n";
}



int main()
{
    
    Employee joe { 14, 32, 24.13 };
    Employee frank { 15, 28, 18.27 };

    //Print joes information
    printEmployee(joe);

    std::cout << "\n";
    //Print franks info
    printEmployee(frank);

    Point3d zero { getZeroPoint() };

    if ( zero.x == 0.0 && zero.y == 0.0 && zero.z == 0)
        std::cout << "The point is zero\n";
    else 
        std::cout << "The point is not zero\n";

    
    Company myCompany { 7, { 1, 32, 55000.0 } };
    std::cout << myCompany.CEO.wage << "\n"; // print the ceos wage

    std::cout << "The size of Foo1 is " << sizeof(Foo1) << "\n";
    std::cout << "The size of Foo2 is " << sizeof(Foo2) << "\n";


    Advertising advertising {};
    std::cout << "How many ads were shown today? Please enter an integer: \n";
    std::cin >> advertising.adsShown;
    std::cout << "What percentage of the ads was clicked on? Please enter a number between 0 and 1.\n";
    std::cin >> advertising.percentAdsClickedOn;
    std::cout << "Please enter the average revenue per add.";
    std::cin >> advertising.averageRevenuePerAd;

    printDataAndCalculateTotalRevenue(advertising);


    printFraction(multiplyFractions(getFraction(), getFraction()));
    return 0;
}
