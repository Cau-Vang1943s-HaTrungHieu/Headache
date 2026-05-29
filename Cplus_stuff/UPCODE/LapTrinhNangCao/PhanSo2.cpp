#include <iostream>

struct Fraction
{
    int nominator, denominator;
    
    void simplification();

    bool operator == (const Fraction& other) const
    {
        // Make local copies since other is constant-bound
        Fraction f1 = *this;
        Fraction f2 = other;
        f1.simplification();
        f2.simplification();
        return (f1.nominator == f2.nominator and f1.denominator == f2.denominator);
    }

    bool operator != (const Fraction& other) const
    {
        return !(*this == other); // why *this? but not this
    }

    Fraction operator + (const Fraction& other) const
    {
        Fraction result;
        result.nominator = this->nominator * other.denominator + other.nominator * this->denominator;
        result.denominator = this->denominator * other.denominator;
        result.simplification(); // always simply after operation
        return result;
    }
};

std::istream& operator >> (std::istream& input, Fraction& fraction)
{
    input >> fraction.nominator >> fraction.denominator;
    return input;
}

std::ostream& operator << (std::ostream& output, const Fraction& fraction)
{
    output << fraction.nominator << "/" << fraction.denominator;
    return output;
}

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

int main()
{
    Fraction fraction;
    Fraction fracSum{0, 1}; // Remember to initialise a structure or a class
    while (std::cin >> fraction)
    {
        fracSum = fracSum + fraction;
    }

    std::cout << fracSum << std::endl;

    return 0;
}

void Fraction::simplification()
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