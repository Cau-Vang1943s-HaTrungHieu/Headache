#include <iostream>
#include <stack>

void chuyenCoso(long soHe10, int heCoSoMoi = 0)
{
    int base;
    const char digits[] = "0123456789ABCDEF"; // Lookup table for hexadecimal
    std::stack<int> stack;

    switch (heCoSoMoi)
    {
        case 0: base = 2; break;
        case 1: base = 8; break;
        case 2: base = 16; break;
    }

    while (soHe10 > 0)
    {
        if (soHe10 == 0)
        {
            std::cout << 0;
            return;
        }

        int remainder = soHe10 % base;
        stack.push(remainder);
        soHe10 /= base;
    }

    while (!stack.empty())
    {
        std::cout << digits[stack.top()];
        stack.pop();
    }
}

int main()
{
    int tenth, choice;
    std::cin >> tenth >> choice;

    chuyenCoso(tenth, choice);

    return 0;
}