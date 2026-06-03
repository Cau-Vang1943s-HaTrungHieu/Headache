#include <iostream>
#include <algorithm>

struct Fraction
{
    int nominator;
    int denominator;

    friend std::istream& operator >> (std::istream& input, Fraction& frac)
    {
        input >> frac.nominator >> frac.denominator;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Fraction frac)
    {
        int gcd = std::__gcd(frac.nominator, frac.denominator);
        frac.nominator /= gcd;
        frac.denominator /= gcd;
        output << frac.nominator << "/" << frac.denominator;
        return output;
    }

    bool operator != (Fraction frac)
    {
        return nominator * frac.denominator != denominator * frac.nominator;
    }
};

struct MixedNumber
{
    Fraction fraction;
    int whole;

    friend std::istream& operator >> (std::istream& input, MixedNumber& figure)
    {
        input >> figure.whole >> figure.fraction;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, MixedNumber figure)
    {
        if (figure.whole != 0) output << figure.whole << " ";
        output << figure.fraction;
        return output;
    }

    MixedNumber toImproperFraction(std::string str = "true")
    {
        Fraction temp;
        MixedNumber result;
        temp.nominator = whole * fraction.denominator + fraction.nominator;
        temp.denominator = fraction.denominator;

        int gcd = std::__gcd(temp.nominator, temp.denominator);
        temp.nominator /= gcd;
        temp.denominator /= gcd;

        if (str == "false")
        {
            result.whole = 0;
            result.fraction = temp;
        }
        else
        {
            result.fraction.nominator = temp.nominator;
            result.fraction.denominator = temp.denominator;
            result.whole = temp.nominator / temp.denominator;
        }
        return result;
    }
    bool operator != (MixedNumber other)
    {
        MixedNumber a = toImproperFraction("false");
        MixedNumber b = other.toImproperFraction("false");
        return a.fraction != b.fraction;
    }

    int combination()
    {
        return whole + fraction.nominator + fraction.denominator;
    }

    bool operator > (MixedNumber other)
    {
        return combination() > other.combination();
    }
};

int main()
{
    MixedNumber a, b;
    std::cin >> a >> b;
    std::string str; std::cin >> str;

    a = a.toImproperFraction(str);
    b = b.toImproperFraction(str);

    std::cout << (a != b ? "TRUE" : "FALSE") << std::endl;
    std::cout << (a > b ? "TRUE" : "FALSE") << std::endl;
    std::cout << a << std::endl << b << std::endl;
    return 0;
}
