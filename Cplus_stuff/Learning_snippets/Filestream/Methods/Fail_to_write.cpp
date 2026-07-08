#include <iostream>
#include <fstream>

int main()
{
    int n;
    std::ofstream writing_file("fail_demo.txt");
    writing_file.close();
    writing_file << n;

    if (writing_file.fail()) std::cout << "Write failed" << std::endl;

    return 0;
}