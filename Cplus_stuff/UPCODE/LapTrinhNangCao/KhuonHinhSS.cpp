#include <iostream>

int gcd(int a, int b)
{
    while (b != 0)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

struct Fraction
{
    int nominator;
    int denominator;

    void simplification()
    {
        int GCD = gcd(nominator, denominator);
        nominator /= GCD;
        denominator /= GCD;

        if (denominator < 0)
        {
            nominator = -nominator;
            denominator = -denominator;
        }
    }

    bool operator == (Fraction& other)
    {
        simplification();
        other.simplification();
        return nominator == other.denominator or denominator == other.denominator;
    }

    friend std::istream& operator >> (std::istream& input, Fraction& frac)
    {
        input >> frac.nominator >> frac.denominator;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Fraction frac)
    {
        output << frac.nominator << "/" << frac.denominator;
        return output;
    }
};

template<typename T>
bool is_equal()
{
    T a, b;
    std::cin >> a >> b;
    return a == b;
}

int main()
{
    char choice; std::cin >> choice;

    switch (choice)
    {
        case 'a': std::cout << (is_equal<int>() ? "true" : "false"); break;
        case 'b': std::cout << (is_equal<double>() ? "true" : "false"); break;
        case 'c': std::cout << (is_equal<Fraction>() ? "true" : "false"); break;
    }

    return 0;
}