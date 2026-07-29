#include <iostream>
#include <algorithm>

class Fraction
{
private:
    int numerator;
    int denominator;
public:
    Fraction(int numerator = 0, int denominator = 1)
    {
        this->numerator = numerator;
        this->denominator = denominator;
    }

    int get_numerator()
    {
        return numerator;
    }

    void set_numerator(int n)
    {
        numerator = n;
    }

    int get_denominator()
    {
        return denominator;
    }

    void set_denominator(int n)
    {
        if (n != 0) denominator = n;
    }

    void normalise()
    {
        int gcd = std::__gcd(numerator, denominator);
        numerator /= gcd;
        denominator /= gcd;
        
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

    friend std::istream& operator>>(std::istream& input, Fraction& frac)
    {
        input >> frac.numerator >> frac.denominator;
        return input;
    }
    
    friend std::ostream& operator<<(std::ostream& output, Fraction frac)
    {
        output << frac.numerator << "/" << frac.denominator;
        return output;
    }

    Fraction reciprocal()
    {
        return Fraction(denominator, numerator);
    }

    Fraction operator+(Fraction& other)
    {
        Fraction result;
        result.numerator = numerator * other.denominator + other.numerator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }
};

int main()
{
    Fraction frac;
    std::cin >> frac;
    Fraction reciprocal_frac = frac.reciprocal();


    std::cout << frac << std::endl;
    std::cout << frac.get_numerator() << std::endl;
    std::cout << frac.get_denominator() << std::endl;
    std::cout << frac.reciprocal() << std::endl;
    frac.normalise();
    std::cout << frac << std::endl;
    std::cout << frac + reciprocal_frac << std::endl;


    return 0;
}