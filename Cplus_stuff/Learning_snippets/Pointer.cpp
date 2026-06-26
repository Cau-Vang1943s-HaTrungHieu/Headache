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