#include <iostream>
#include <cmath>

double fact(double n)
{
    if (n == 1) return 1;
    return fact(n - 1) * n;
}

double S(double n, double x)
{
    if (n == 0) return x;
    return S(n - 1, x) + std::pow(-1, n) * (std::pow(x, 2*n+1) / fact(2*n+1));
}

int main()
{
    double n, x; std::cin >> n >> x;

    std::cout << std::roundf(S(n, x) * 1000) / 1000 << std::endl;

    return 0;
}