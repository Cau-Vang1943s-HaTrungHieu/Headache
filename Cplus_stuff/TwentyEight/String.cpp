/**

String data type is basically a group of character data types (char) that let
us modify, change, insert, etc. a sentence, phrase dynamically.

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


    return 0;
}
