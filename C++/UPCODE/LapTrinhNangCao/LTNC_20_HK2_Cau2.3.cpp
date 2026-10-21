#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

double S(int n)
{
    if (n == 1) return std::sqrt(2);
    return std::sqrt(2 + S(n - 1));
}

int main()
{
    int n; std::cin >> n;

    // std::cout << roundf(S(n) * 1000 ) / 1000 << std::endl;
    std::cout << std::fixed << std::setprecision(3) << S(n) << std::endl;;

    return 0;
}