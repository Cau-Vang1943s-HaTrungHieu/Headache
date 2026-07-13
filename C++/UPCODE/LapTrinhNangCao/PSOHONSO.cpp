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

    friend std::istream& operator >> (std::istream& input, Fraction& frac)
    {
        input >> frac.nominator >> frac.denominator;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const Fraction& frac)
    {
        output << frac.nominator << "/" << frac.denominator;
        return output;
    }

    bool operator != (const Fraction& other)
    {
        Fraction this_frac = *this, other_frac = other;
        this_frac.simplification();
        other_frac.simplification();
        return (this_frac.nominator != other_frac.nominator or this_frac.denominator != other_frac.denominator);
    }

    Fraction operator + (const Fraction& other)
    {
        Fraction result;
        result.nominator = nominator * other.denominator + other.nominator * denominator;
        result.denominator = denominator * other.denominator;
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
        input >> figure.whole >> figure.fraction.nominator >> figure.fraction.denominator;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const MixedNumber& figure)
    {
        if (figure.whole != 0) {
            output << figure.whole << " " << figure.fraction.nominator << "/" << figure.fraction.denominator;
        }
        else
        {
            output << figure.fraction.nominator << "/" << figure.fraction.denominator;
        }
        return output;
    }

    void toImproperFraction(bool doConvert = true)
    {
        fraction.simplification();
        if (doConvert)
        {
            whole += fraction.nominator / fraction.denominator;
            fraction.nominator = fraction.nominator % fraction.denominator;
        }
        else 
        {
            fraction.nominator = whole * fraction.denominator + fraction.nominator;
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
        return whole + fraction.nominator + fraction.denominator;
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
