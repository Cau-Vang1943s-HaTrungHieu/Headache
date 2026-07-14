#include <iostream>
#include <fstream>

int main()
{
    std::ofstream writing_file;
    writing_file.open("output.txt");

    if (!writing_file.is_open())
    {
        std::cout << "Khong mo duoc file!";
    }
    // Try enable the text file to be read-only and see what will happen

    writing_file << "Hello world!" << std::endl;

    return 0;
}