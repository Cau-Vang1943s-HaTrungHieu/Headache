#include <iostream>
#include <cmath>
#include <iomanip>

double S(int n, int x)
{
    if (n == 0) return 0;
    
    long long fact = 1;
    for (int i = 2; i <= n; i++)
    {
        fact *= i;
    }
    
    return S(n - 1, x) + static_cast<double>(std::pow(x, n)) / fact;
}

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::cout << std::fixed << std::setprecision(3) << S(n, x) << std::endl;
    return 0;
}