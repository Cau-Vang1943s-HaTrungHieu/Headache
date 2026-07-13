/**

There are two concepts for templatised data type:
- Template for functions
- Template for classes
What in this file is all about the first concept

We use templatised data type for a function arguments
With the arguments templatised, you don't need to specify their types, which means it could be any types (int, str, char, etc.)
    + Whatever the types, if there are more than two passing arguments, they have to be the same type.
    + If you want to pass arguments that are of different types, you need to need a "two-parameter template".
Templatised data type helps reduce the amount of function overloading in your code. For example:

Instead of overloading a bunch of functions:
---
void swap(int& a, int& b); --> This swaps the value of two integers
void swap(std::string& a, std::string& b); --> this swap the value of two strings

We can make it look tidier like this:
---
template<typename T>
void swap(T& a, T&b);

To make a template function call in your code:
---
youFunction<type>(parameters...);

**/

#include <iostream>

template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

int main()
{
    int a, b;
    std::cin >> a >> b;
    std::cout << "Before swapping: " << a << " " << b << std::endl;
    swap(a, b);
    std::cout << "After swapping: " << a << " " << b << std::endl;

    std::string x, y;
    std::cin >> x >> y;
    std::cout << "Before swapping: " << x << " " << y << std::endl;
    swap(x, y);
    std::cout << "After swapping: " << x << " " << y << std::endl;



    return 0;
}
