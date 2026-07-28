#include <iostream>
#include <cmath>

double factorial(double n)
{
    if (n <= 1) return 1;
    return factorial(n - 1) * n;
}

double sine(double x, double n = 10)
{
    if (n == 0) return x;
    return sine(x, n - 1) + std::pow(-1, n) * (pow(x, 2*n+1) / factorial(2*n+1));
}

double cosine(double x, double n = 10)
{
    if (n == 0) return 1;
    return cosine(x, n - 1) +std::pow(-1, n) * (pow(x, 2*n) / factorial(2*n));
}

int main()
{
    double x; std::cin >> x;
    std::cout << roundf(sine(x) * 100) / 100 << std::endl;
    std::cout << roundf(cosine(x) * 100) / 100 << std::endl;

    return 0;
}