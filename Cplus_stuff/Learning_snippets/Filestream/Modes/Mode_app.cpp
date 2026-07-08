#include <iostream>
#include <fstream>

int main()
{
    // append --> always force put pointer to the end before writing
    std::ofstream writing_file("app.txt", std::ios::app);
    writing_file << "Hello World!" << std::endl;
    writing_file << "Bye!" << std::endl;

    writing_file.close();

    return 0;
}

/*

Symbols:

\r --> Carriage return. Heads back to the beginning of the line.
\n --> New line (or line feed)
    - In Window, this symbol is translated into \r\n meaning the 
    typing cursor will get to a new line then start from the 
    beginning of that line.

*/