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
        // frac.simplification();
        output << frac.nominator << "/" << frac.denominator;
        return output;
    }

    int operator ++ ()
    {
        return nominator++;
    }

    int operator -- ()
    {
        return nominator--;
    }
};

int main()
{
    Fraction fraction;
    std::string operat0r;
    std::cin >> fraction >> operat0r;

    std::cout << fraction << std::endl;

    if (operat0r == "++") ++fraction;
    else if (operat0r == "--") --fraction;

    std::cout << fraction << std::endl;

    return 0;
}