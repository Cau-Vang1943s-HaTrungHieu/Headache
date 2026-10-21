#include <iostream>

long long fact(int n)
{
    if (n <= 1) return 1;
    return fact(n - 1) * n;
}

long long S(int n)
{
    if (n == 1) return 1;
    return S(n - 1) + fact(n);
}

int main()
{
    int n; std::cin >> n;
    std::cout << S(n) << std::endl;
    return 0;
}