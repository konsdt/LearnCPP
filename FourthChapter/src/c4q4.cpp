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
    double fallenDistance{};
    fallenDistance = (gravityConstant * seconds * seconds) / 2.0;
    return fallenDistance;
}

void printCurrentHeight(double towerHeight, int seconds)
{   
    const double fallenDistance{ fallenHeight(seconds)};
    
    if (fallenDistance < towerHeight)
        std::cout << "At " << seconds << " seconds, the ball is at height "
            << towerHeight - fallenDistance << "m. \n";    
    else
        std::cout << "The ball has reached the ground."; 
}    
int main()
{
    const double towerHeight{ getTowerHeight() };
    printCurrentHeight( towerHeight, 0 );
    printCurrentHeight( towerHeight, 1 );
    printCurrentHeight( towerHeight, 2 );
    printCurrentHeight( towerHeight, 3 );
    printCurrentHeight( towerHeight, 4 );
    printCurrentHeight( towerHeight, 5 );
    return 0;

}
