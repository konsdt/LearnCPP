#include <iostream>
#include <string>

int main()
{
  std::string str{ "I saw a red car yesterday." };

  str.replace(7, 4, " blue");

  std::cout << str << '\n'; // I saw a blue car yesterday.

  return 0;
}
