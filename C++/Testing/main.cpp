#include <iostream>
#include <fstream>

int main()
{
    int n;
    std::string str;
    std::cin >> n;
    std::cout << n;
    std::getline(std::cin, str);
    std::cout << str << std::endl;

    return 0;
}