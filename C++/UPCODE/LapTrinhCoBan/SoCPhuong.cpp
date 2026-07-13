#include <iostream>
#include <cmath>

bool is_perfect_sqr(int num)
{
    int sqrnum = sqrt(num);
    return sqrnum * sqrnum == num;
}

int main()
{
    int n; std::cin >> n;
    std::cout << (is_perfect_sqr(n) ? "yes" : "no") << std::endl;

    return 0;
}