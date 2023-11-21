#include <iostream>
#include<string>
#include<vector>

void longestCommonPrefix(std::vector<std::string>& strs) {
        for(std::string string: strs){
            std::cout << string.length() << std::endl;
        }

}



int main() {    
    std::vector<std::string> strs {"OneString"};
    longestCommonPrefix(strs);
    return 0;
}
