#include <iostream>

int another_sum(int n)
{
    if (n < 10) return n;

    int sum = 0;
    while (n > 0)
    {
        int digit = n % 10;
        sum += digit;
        n /= 10;
    }
    return another_sum(sum);
}

/*
    79 --> 7 + 9

*/

int main()
{
    int n; std::cin >> n;

    std::cout << another_sum(n) << std::endl;

    return 0;
}