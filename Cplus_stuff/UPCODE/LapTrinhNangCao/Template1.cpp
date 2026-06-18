#include <iostream>

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
        output << frac.nominator << "/" << frac.denominator;
        return output;
    }

    bool operator < (Fraction& other)
    {
        return nominator * other.denominator < denominator * other.nominator;
    }
};

template <typename T>
void max_of()
{
    T a, b, c;
    std::cin >> a >> b >> c;
    T max = a;
    if (max < b) max = b;
    if (max < c) max = c;
    
    std::cout << max;
}

int main()
{
    char choice;
    std::cin >> choice;

    switch (choice)
    {
        case 'a': max_of<int>(); break;
        case 'b': max_of<double>(); break;
        case 'c': max_of<Fraction>(); break;
    }

    return 0;
}
