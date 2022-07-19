#include<iostream>


double getTowerHeight() 
{
    double towerHeight{};
    std::cout << "Enter the height of the tower in meters: ";
    std::cin >> towerHeight;
    return towerHeight;
}


double fallenHeight(int seconds)
{
    constexpr double gravityConstant {9.81};
    double fallenDistance;
    fallenHeight = (gravityConstant * seconds * seconds) / 2;
    return fallenHeight;
}

void printCurrentHeight(double towerHeight)
{   
    
    std::cout << "At 0 seconds, the ball is at height" << towerHeight << '\n';
}
int main()
{
    double towerHeight{ getTowerHeight };
    printCurrentHeight( towerHeight );
    return 0;

}
