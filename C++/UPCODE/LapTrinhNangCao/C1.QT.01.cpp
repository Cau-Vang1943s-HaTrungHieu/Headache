#include <iostream>
#include <algorithm>

struct Fraction
{
    int numerator;
    int denominator;

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
        frac.normalise();
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Fraction frac)
    {
        output << frac.numerator << "/" << frac.denominator;
        return output;
    }
};

struct Complex
{
    int real, image;

    friend std::istream& operator>>(std::istream& input, Complex& cmplx)
    {
        input >> cmplx.real >> cmplx.image;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Complex cmplx)
    {
        if (cmplx.real != 0) output << cmplx.real;

        if (cmplx.image != 0)
        {
            if (cmplx.image > 0 and cmplx.real != 0) output << "+";
            if (cmplx.image < 0) output << "-";
            if (std::abs(cmplx.image) != 1) output << std::abs(cmplx.image);
            output << "i";
        }

        if (cmplx.real == 0 and cmplx.image == 0) output << 0;
        return output;
    }

    Complex operator+(const Complex& other) const
    {
        Complex result;
        result.real = real + other.real;
        result.image = image + other.image;
        return result;
    }

    Complex operator+(const int& n) const
    {
        Complex result;
        result.real = real + n;
        result.image = image;
        return result;
    }

    Complex operator+(const Fraction& frac) const
    {
        Complex result;
        result.real = real + frac.numerator;
        result.image = image + frac.denominator;
        return result;
    }
};

int main()
{
    Complex cmplx;
    std::cin >> cmplx;

    char choice; std::cin >> choice;
    std::cout << cmplx << std::endl;
    switch (choice)
    {
    case 'i':
        int n; std::cin >> n;
        std::cout << n << std::endl;
        std::cout << cmplx + n << std::endl;
        break;
    case 'z':
        Complex another_cmplx;
        std::cin >> another_cmplx;
        std::cout << another_cmplx << std::endl;
        std::cout << cmplx + another_cmplx << std::endl;
        break;
    case 'p':
        Fraction frac;
        std::cin >> frac;
        std::cout << frac << std::endl;
        std::cout << cmplx + frac << std::endl;
        break;
    default: break;
    }
    return 0;
}
