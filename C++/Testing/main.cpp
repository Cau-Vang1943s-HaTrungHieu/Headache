#include <iostream>
#include <string>

int main()
{
    std::string line;
    getline(std::cin, line);
    std::cout << line.length() << std::endl;
    std::cout << line.size() << std::endl;
    return 0;
}