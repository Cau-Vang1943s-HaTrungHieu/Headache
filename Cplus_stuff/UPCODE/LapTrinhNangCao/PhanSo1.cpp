#include <iostream>
#include <algorithm>

struct Fraction
{
    int nominator;
    int denominator;

    void simplification()
    {
        int gcd = std::__gcd(nominator, denominator);
        nominator /= gcd;
        denominator /= gcd;

        if (denominator < 0)
        {
            nominator = -nominator;
            denominator = -denominator;
        }
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

    Fraction operator + (Fraction other)
    {
        Fraction result;
        result.nominator = nominator * other.denominator + other.nominator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplification();
        return result;
    }
};

int main()
{
    Fraction frac1, frac2;
    
    std::cin >> frac1 >> frac2;

    if (frac1.denominator == 0 or frac2.denominator == 0)
    {
        std::cout << -1;
        return 0;
    }

    // Fraction fracsum = frac1 + frac2;
    std::cout << frac1 + frac2 << std::endl;

    return 0;
}