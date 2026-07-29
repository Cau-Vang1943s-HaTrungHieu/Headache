#include <iostream>
#include <cmath>

long long S(int n, int x)
{
    if (n == 0) return 0;
    return S(n - 1, x) + static_cast<long long>(std::pow(x, 2*n));
}

int main()
{
    int n, x;
    std::cin >> n >> x;
    std::cout << S(n, x);

    return 0;
}