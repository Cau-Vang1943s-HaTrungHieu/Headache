#include <iostream>
#include <fstream>

int main()
{
    std::ifstream reading_file("fail_demo.txt");

    int numbers[10];
    int i = 0;
    while (i < 10 and reading_file >> numbers[i]) i++;
    
    if (reading_file.fail()) std::cout << "Read failed!" << std::endl;  

    for (int j = 0; j < i; j++)
    {
        std::cout << numbers[j] << std::endl;
    }

    return 0;
}