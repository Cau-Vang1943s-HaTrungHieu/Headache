#include <iostream>
#include <fstream> // Essential library

int main()
{
    std::ofstream writing_file("output.txt"); // Instantiate the object for writing
    /*  Other way
    
    std::ofstream writing_file;
    writing_file.open("output.txt");

    The program automatically create a new file if there isn't any files matching your file name

    */
    
    writing_file << "Hello world!" << std::endl;
    

    // Test with array
    std::string names[] = {"Hieu", "Lan", "Vinh"};

    for (int i = 0; i < (sizeof(names) / sizeof(names[0])); i++)
    {
        writing_file << names[i] << std::endl;
    }

    writing_file << "Lorem Ipsum is dummy or placeholder text commonly used in graphic design, publishing, and web development to fill layouts and demonstrate visual elements without distracting from the design itself. It allows designers to focus on typography, spacing, and layout rather than the content";
    std::cout << writing_file.tellp() << std::endl;
    
    writing_file.seekp(0, std::ios::end);
    std::cout << writing_file.tellp();

    writing_file.close(); // Closing file is automatic unless you need to

    return 0;
}