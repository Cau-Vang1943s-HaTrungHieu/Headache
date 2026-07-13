#include <iostream>
#include <fstream>

int main()
{
    std::ifstream reading_file("output.txt");
    reading_file.seekg(0, std::ios::end);
    std::cout << reading_file.tellg() << std::endl;
    char character;
    reading_file >> character;
    std::cout << character << std::endl;

    return 0;
}