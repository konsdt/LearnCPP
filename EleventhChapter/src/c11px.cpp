#include<iostream>
#include<array>
#include<algorithm>
#include<numeric>
#include<string>
#include<vector>

// Question 1
namespace ItemFunctions
{
int countTotalItems(auto& numberOfItems)
{
    return std::reduce(numberOfItems.begin(), numberOfItems.end());
}
}
//Question 2

struct PersonalizedGrades
{
    int grade {};
    std::string first_name {};
};

bool sortAfterGrades(PersonalizedGrades& a, PersonalizedGrades& b)
{
    return (a.grade > b.grade);
}

// Question 3

void swapValues(int& a, int& b)
{
    int temp {a};
    a = b;
    b = temp;
}

// Question 5

void printCstyleString(char* stringArray)
{
    for (char* begin{stringArray}; *begin != '\0'; ++begin)
    {
        std::cout << *begin << '\n';
    }
}

int main()
{
    enum Item
    {
        health_potions,
        torches,
        arrows
    };

    std::array<int, 3> numberOfItems {2, 5, 10};

    std::cout << ItemFunctions::countTotalItems(numberOfItems) << '\n';


    //Question 2
    int numberOfStudents {};
    std::cout << "How many students do you want to enter?: ";
    std::cin >> numberOfStudents;
    std::vector<PersonalizedGrades> Grades(numberOfStudents);
    std::cout << "Please enter name and points: " << '\n';
    for (PersonalizedGrades& student : Grades)
    {
        std::cout << "Please enter name: ";
        std::cin >> student.first_name;
        std::cout << "Please enter grade: ";
        std::cin >> student.grade;
    }
    std::cout << '\n';
    std::sort(Grades.begin(), Grades.end(), sortAfterGrades);

    for (PersonalizedGrades& student : Grades)
    {
        std::cout << student.first_name << " got grade " << student.grade << ".\n";
    }

    //Question 3
    int a {10};
    int b {20};

    swapValues(a, b);

    std::cout << "a: " << a << " b: " << b << '\n';


    // Question 4
    char string[]{"Hello World!"};

    printCstyleString(string);
    return 0;
}
