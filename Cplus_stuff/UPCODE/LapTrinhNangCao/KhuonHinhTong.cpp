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
        frac.simplification();
        output << frac.nominator << "/" << frac.denominator;
        return output;
    }

    Fraction operator + (Fraction& other)
    {
        Fraction result;
        result.nominator = this->nominator * other.denominator + other.nominator * this->denominator;
        result.denominator = this->denominator * other.denominator;
        return result;
    }
};

template<typename T>
struct Array
{
    T values[99];
    int size = 0;

    void input()
    {
        T temp;
        std::cin >> temp;
        values[size++] = temp;
        return;
    }

    T sum()
    {
        T result = values[0];
        for (int i = 1; i < size; i++)
        {
            result = result + values[i];
        }
        return result;
    }
};

int main()
{
    char choice;
    Array<int> int_array;
    Array<Fraction> fraction_array;

    while (std::cin >> choice)
    {
        if (choice == 'a') int_array.input();
        else if (choice == 'b') fraction_array.input();
    }

    if (int_array.size != 0) std::cout << int_array.sum() << std::endl;
    else std::cout << "khong co" << std::endl;

    if (fraction_array.size != 0) std::cout << fraction_array.sum() << std::endl;
    else std::cout << "khong co" << std::endl;

    return 0;
}