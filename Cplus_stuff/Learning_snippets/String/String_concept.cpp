/**

String data type is basically a group of character data types (char) that let
us modify, change, insert, etc. a sentence, phrase dynamically.
There are two way to declare string data types:
C style
---
char name[] = "Hieu"; // This gives us "Hieu\0", \0 is null terminating symbol

    - C string isn't limited to its size, meaning it cannot be 
    changed or modified after declaration.

C++ style
---
#include <string>
...
std::string name = "Hieu";

    - C++ string is more flexible. Since this data type comes from
    a string class, it has many useful methods that we can use to
    work with.
    - Some features of C++ string or string class:
        + Appendable with + , +=
        + Check the length of a string with length();

**/

#include <iostream>
#include <string> // include string library to unlock full potential of string data type

int main()
{
    std::string s;
    std::cin >> s; // This only get the first word of a sentence (separated by spaces)
    std::cout << s << std::endl;

    std::cin.ignore();
    getline(std::cin, s); // This will get the whole sentence
    std::cout << s << std::endl;

    // string traversal
    std::string myCountry = "viet nam";
    for (int i = 0; i < myCountry.length(); i++)
    {
        myCountry[i] = toupper(myCountry[i]);
    }
    std::cout << myCountry << std::endl;

    myCountry = "Toi yeu " + myCountry;
    std::cout << myCountry << std::endl;
    
    std::cout << myCountry.length() << std::endl;

    return 0;
}
