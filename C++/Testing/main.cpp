#include <iostream>

void print_conversion(long soHe10, int heCoSoMoi = 0)
{
    int base;
    const char digits[] = "0123456789ABCDEF";

    switch (heCoSoMoi)
    {
        case 0: base = 2; break;
        case 1: base = 8; break;
        case 2: base = 16; break;
    }

    if (soHe10 < base)
    {
        std::cout << soHe10;
        return;
    }

    print_conversion(soHe10 / base, heCoSoMoi);
    std::cout << digits[soHe10 % base];
}

int main()
{
    int tenth, choice;
    std::cin >> tenth >> choice;

    print_conversion(tenth, choice);    

    return 0;
}