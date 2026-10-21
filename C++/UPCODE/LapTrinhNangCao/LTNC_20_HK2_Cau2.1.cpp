#include <iostream>
#include <algorithm>
#include <cmath>

double S(int n)
{
    if (n == 1) return 1;
    return std::sqrt(n + S(n - 1));
}

int main()
{
    int n; std::cin >> n;

    std::cout << roundf(S(n) * 1000) / 1000 << std::endl;

    return 0;
}