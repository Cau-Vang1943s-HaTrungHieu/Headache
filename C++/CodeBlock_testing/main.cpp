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
    int numerator;
    int denumerator;

    void simplification()
    {
        int GCD = gcd(numerator, denumerator);
        numerator /= GCD;
        denumerator /= GCD;

        if (denumerator < 0)
        {
            numerator = -numerator;
            denumerator = -denumerator;
        }
    }

    friend std::istream& operator >> (std::istream& input, Fraction& frac)
    {
        input >> frac.numerator >> frac.denumerator;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const Fraction& frac)
    {
        output << frac.numerator << "/" << frac.denumerator;
        return output;
    }

    bool operator != (const Fraction& other)
    {
        Fraction this_frac = *this, other_frac = other;
        this_frac.simplification();
        other_frac.simplification();
        return (this_frac.numerator != other_frac.numerator or this_frac.denumerator != other_frac.denumerator);
    }

    Fraction operator + (const Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denumerator + other.numerator * denumerator;
        result.denumerator = denumerator * other.denumerator;
        result.simplification();
        return result;
    }
};

struct MixedNumber
{
    Fraction fraction;
    int whole;

    friend std::istream& operator >> (std::istream& input, MixedNumber& figure)
    {
        input >> figure.whole >> figure.fraction.numerator >> figure.fraction.denumerator;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const MixedNumber& figure)
    {
        if (figure.whole != 0) {
            output << figure.whole << " " << figure.fraction.numerator << "/" << figure.fraction.denumerator;
        }
        else
        {
            output << figure.fraction.numerator << "/" << figure.fraction.denumerator;
        }
        return output;
    }

    void toImproperFraction(bool doConvert = true)
    {
        fraction.simplification();
        if (doConvert)
        {
            whole += fraction.numerator / fraction.denumerator;
            fraction.numerator = fraction.numerator % fraction.denumerator;
        }
        else
        {
            fraction.numerator = whole * fraction.denumerator + fraction.numerator;
            whole = 0;
            fraction.simplification();
        }
    }

    bool operator != (const MixedNumber& other)
    {
        return (whole != other.whole or fraction != other.fraction);
    }

    int sum_of_all() const
    {
        return whole + fraction.numerator + fraction.denumerator;
    }

    bool operator > (const MixedNumber& other)
    {
        return sum_of_all() > other.sum_of_all();
    }
};

int main()
{
    MixedNumber figure1, figure2;
    std::string conversion;
    std::cin >> figure1 >> figure2 >> conversion;

    std::cout << (figure1 != figure2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << (figure1 > figure2 ? "TRUE" : "FALSE") << std::endl;

    if (conversion == "true")
    {
        figure1.toImproperFraction(true);
        figure2.toImproperFraction(true);
    }
    else
    {
        figure1.toImproperFraction(false);
        figure2.toImproperFraction(false);
    }

    std::cout << figure1 << std::endl;
    std::cout << figure2 << std::endl;

    return 0;
}
