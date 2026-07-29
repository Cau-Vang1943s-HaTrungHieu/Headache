#include <iostream>

int fibo(int n)
{
    if (n == 1) return 1;
    if (n == 2) return 1;
    return fibo(n - 1) + fibo(n - 2);
}

int main()
{
    int n; std::cin >> n;
    std::cout << fibo(n) << std::endl;

    return 0;
}