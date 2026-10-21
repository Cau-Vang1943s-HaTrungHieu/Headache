#include <iostream>
#include <iomanip>

long long int_S(int n);

double S(int n)
{
    if (n == 1) return 1;
    return S(n - 1) + 1.0 / int_S(n);
}

int main()
{
    int n; std::cin >> n;
    std::cout << std::fixed << std::setprecision(3) << S(n) << std::endl;

    return 0;
}

long long int_S(int n)
{
    if (n == 1) return 1;
    return int_S(n - 1) + n;
}