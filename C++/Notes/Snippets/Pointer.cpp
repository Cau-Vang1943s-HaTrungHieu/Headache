/*
    - If a pointer points to NULL, that means its data (is it data?) is 0
    - If we dereference a pointer, that means we are using the 
    pointer to access its data.
*/

#include <iostream>

int main()
{
    int* ptr;
    int* ptr2;
    int x = 20;
    ptr = &x;
    ptr2 = ptr;

    std::cout << *ptr << std::endl;
    std::cout << *ptr2 << std::endl;

    x = 40;
    std::cout << *ptr << std::endl;
    std::cout << *ptr2 << std::endl;

    return 0;
}