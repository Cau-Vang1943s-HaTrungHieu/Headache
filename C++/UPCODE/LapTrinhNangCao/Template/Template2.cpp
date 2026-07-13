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
        result.nominator = nominator * other.denominator + other.nominator * denominator;
        result.denominator = denominator * other.denominator;
        return result;
    }
};

template<typename T>
struct Array
{
    T values[99];
    int size;

    T sum()
    {
        T result = values[0];
        for (int i = 1; i < size; i++)
        {
            result = result + values[i];
        }
        return result;
    }

    friend std::istream& operator >> (std::istream& input, Array<T> &arr)
    {
        arr.size = 0;
        while (input >> arr.values[arr.size])
        {
            arr.size++;
        }
        return input;
    }
};

template<typename T>
T arr_sum()
{
    Array<T> arr;
    std::cin >> arr;
    return arr.sum();
}

int main()
{
    char c; std::cin >> c;

    switch (c)
    {
        case 'a': std::cout << arr_sum<int>(); break;
        case 'b': std::cout << arr_sum<Fraction>(); break;
    }

    return 0;
}