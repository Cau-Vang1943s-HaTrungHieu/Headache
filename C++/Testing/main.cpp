#include <iostream>

bool isPrime(long long number)
{
    if (number < 2)
    {
        return false;
    }

    for (long long divisor = 2; divisor <= number / divisor; ++divisor)
    {
        if (number % divisor == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    int limit;
    if (!(std::cin >> limit))
    {
        return 1;
    }

    bool firstPrime = true;
    for (long long number = 2; number <= limit; ++number)
    {
        if (isPrime(number))
        {
            if (!firstPrime)
            {
                std::cout << ' ';
            }
            std::cout << number;
            firstPrime = false;
        }
    }
    std::cout << '\n';

    return 0;
}
