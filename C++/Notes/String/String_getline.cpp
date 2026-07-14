/*

As you may have noticed when we use cin >> to input a string. For
instance: "Hello World" and then output the string. It only gives
us Hello. The reason is that the "cin >>" stops taking characters
when it reaches some white space symbols such as \n for new line, 
\t for tab, or space.

*/

#include <iostream>
#include <string>

int main()
{
    std::string text;
    std::string whole_text;
    std::cin >> text;
    /*
        "Hello World" goes into the buffer but only Hello is assigned
        to text, "World" is stuck in the input stream
    */
    std::cout << text << std::endl;
    std::string left_over;
    std::cin >> left_over;
    std::cout << left_over << std::endl;

    // to get the whole text, you use getline() function
    std::cin.ignore();
    getline(std::cin, whole_text);
    std::cout << whole_text << std::endl;

    return 0;
}