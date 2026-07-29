#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;
public:
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
};

int main()
{
    Fraction frac;
    std::cin >> frac;
    std::cout << frac << std::endl;
    
    return 0;
}