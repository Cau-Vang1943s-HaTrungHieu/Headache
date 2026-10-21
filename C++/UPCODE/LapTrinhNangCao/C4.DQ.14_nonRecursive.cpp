#include <iostream>
#include <iomanip>

double S(int n)
{
    if (n == 1) return 1;

    int denominator = 1;
    for (int i = 2; i <= n; i++)
    {
        denominator += i;
    }

    return S(n - 1) + 1.0 / denominator;
}

int main()
{
    int n; std::cin >> n;
    std::cout << std::fixed << std::setprecision(3) << S(n) << std::endl;

    return 0;
}