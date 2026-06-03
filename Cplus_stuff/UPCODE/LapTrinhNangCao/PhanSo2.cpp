#include <iostream>

struct Fraction
{
    int nominator;
    int denominator;

    void simplification();

    bool operator == (Fraction other)
    {
        simplification();
        other.simplification();
        return (nominator == other.nominator or denominator == other.denominator);
    }

    bool operator != (Fraction other)
    {
        return !(*this == other);
    }

    Fraction operator + (Fraction other)
    {
        Fraction result;
        result.nominator = nominator * other.denominator + other.nominator * denominator;
        result.denominator = denominator * other.denominator;
        result.simplification();
        return result;
    }
};

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

std::istream& operator >> (std::istream& input, Fraction& frac)
{
    input >> frac.nominator >> frac.denominator;
    return input;
}

std::ostream& operator << (std::ostream& output, Fraction& frac)
{
    output << frac.nominator << "/" << frac.denominator;
    return output;
}

struct FractionArray
{
    Fraction indices[999];
    int s1ze;

    Fraction& operator [] (int index)
    {
        return indices[index];
    }
};

std::istream& operator >> (std::istream& input, FractionArray& arr)
{
    arr.s1ze = 0;
    while (input >> arr.indices[arr.s1ze])
    {
        arr.s1ze++;
    }
    return input;
}

std::ostream& operator << (std::ostream& output, FractionArray& arr)
{
    for (int i = 0; i < arr.s1ze; i++)
    {
        output << arr.indices[i] << " ";
    }
    return output;
}

int main()
{
    FractionArray arr;
    std::cin >> arr;
    Fraction fracsum{0, 1};
    for (int i = 0; i < arr.s1ze; i++)
    {
        fracsum = fracsum + arr[i];
    }
    std::cout << fracsum << std::endl;

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
