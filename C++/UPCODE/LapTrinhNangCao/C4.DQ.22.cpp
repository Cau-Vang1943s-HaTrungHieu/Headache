#include <iostream>
#include <cmath>
#include <iomanip>

double S(int n, double radians)
{
    if (n == 1) return std::sin(radians) + std::cos(radians);
    return S(n - 1, radians) + std::sin(n * radians) + cos(n * radians);
}

int main()
{
    int n;
    double degree;
    std::cin >> n >> degree;

    // From degree to rad
    double radians = degree * M_PI / 180.0;
    double result = S(n, radians);

    std::cout << std::fixed << std::setprecision(3) << result << std::endl;

    return 0;
}