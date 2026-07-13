/*

Reading from file:
- ifstream <reading variable>("path", mode);
- The program will read a piece of data (depending on how users command
it to read) and jot them down in a variable, an object, a vector, etc.
- How the program jots down depends heavily on data type, for example.
If the data type is a string, the program will output the object's 
content chunk by chunk on each line when users attempt to read it.

Notice:
- Writing to file automatically create a new file for us if the file
specified in the path argument doesn't exist.
- However, this is not the case for Reading from file, the file 
must exist in order to be read properly. Thus, you should check
whether the file is open or not after having created an input object
of the file.

*/

#include <iostream>
#include <fstream>
#include <vector>

int main()
{
    std::ifstream reading_file("output.txt", std::ios::binary);
    if (!reading_file.is_open())
    {
        std::cout << "Cannot open file!" << std::endl;
        return 0;
    }

// Reading string
    std::vector<std::string> text;
    std::string input;
    // while (reading_file >> input) text.push_back(input);
    while (getline(reading_file, input)) text.push_back(input);
    std::cout << reading_file.tellg() << std::endl;
    
    for (std::string t : text) std::cout << t << std::endl;

// Reading characters
    /*
        - Apart from getline(), which is a function itself, get() is
        a method of an ifstream object.
    */
    reading_file.clear(); // Clear the previous input
    reading_file.seekg(0, std::ios::beg); // navigate to the beginning of the file

    char character = reading_file.get(); // Pick the first character of the text
    std::cout << character << std::endl;

    return 0;
}