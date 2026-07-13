#include <iostream>
#include <fstream>

int main()
{
    // ate - ofstream
    std::ofstream writing_file("ate.txt", std::ios::ate);
    std::cout << writing_file.tellp() << std::endl;
    writing_file << "This is  the end!" << std::endl;
    std::cout << writing_file.tellp() << std::endl;
    writing_file.close();

    // ate - fstream
    std::fstream file("ate.txt", std::ios::out | std::ios::app);
    /*
        std::fstream file ("ate.txt", std::ios::in | std::ios::out | std::ios::ate);
        - Same expression
        - But give you more control over your file.\
        - to avoid truncation from ios::out, you need to open the file 
        for both reading and writing.
    */
    file << "Y";

    // ate - ifstream
    std::ifstream reading_file("ate.txt", std::ios::ate);


    return 0;
}