#include <iostream>

void print_binary(int n)
{
    if (n == 0) return;
    print_binary(n / 2);
    std::cout << n % 2;
}

int main()
{
    int n; std::cin >> n;
    print_binary(n);

    return 0;
}