#include <iostream>
#include <fstream>

int main()
{
    int a, b;
    
    std::ifstream fin("input.txt");
    if (!fin.is_open())
    {
        std::cout << "Cannot open file." << std::endl;
        return -1;
    }
    fin >> a >> b;
    fin.close();

    std::cout << a + b << std::endl;


    return 0;
}