#include <iostream>

int sum_digits(int n)
{
    if (n <= 0) return 0;
    return sum_digits(n / 10) + n % 10;
}

int main()
{
    int n; std::cin >> n;
    std::cout << sum_digits(n) << std::endl;

    return 0;
}