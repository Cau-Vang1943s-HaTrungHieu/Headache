/**

About the second concept, which is a template for classes:
It works just the same as a template for functions (declaration, calling).

To create a T type for a class:
---
template<typename T>
class
{
    Methods and attributes go here...
};

This is how the class' template is used in your main block:
---
className<typeName> instanceName

- The typeName will substitute every instance of the T type in the className which
is essentially a struct or a class (e.g., typeName = int --> T = int;
typeName = Fraction --> T = Fraction)
- Any types that are not T types inside a struct or a class stay the same.
No changes are applied to them, and they still do their job as methods or
attributes.

The example below shows how a class template works by making an Array struct
that can contain elements of type integer, double, or the custom type Fraction.

**/

#include <iostream>
#include <algorithm>

// Kieu phan so
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

    friend std::ostream& operator << (std::ostream& output, const Fraction frac)
    {
        output << frac.nominator << "/" << frac.denominator;
        return output;
    }

    // So sanh phan so nho hon
    bool operator < (Fraction& other)
    {
        return (double) nominator / denominator < (double) other.nominator / other.denominator;
    }
};

template<typename T> // template for Array struct
struct Array
{
    T values[99];
    int size = 0;   // Remember to initialise array's size

    // Get array values from input
    void input()
    {
        T n;
        std::cin >> n;
        values[size++] = n;
        return;
    }

    // Find the minimum value of each array.
    T min()
    {
        T min = values[0];
        for (int i = 1; i < size; i++)
        {
            if (values[i] < min) min = values[i];
        }
        return min;
    }
};

int main()
{
    char choice;
    Array<int> int_array; // Instantiate an object
    Array<double> double_array;
    Array<Fraction> fraction_array;

    while (std::cin >> choice)
    {
        if (choice == 'a') int_array.input();
        else if (choice == 'b') double_array.input();
        else if (choice == 'c') fraction_array.input();
    }

    if (int_array.size > 0) std::cout << int_array.min() << std::endl;
    else std::cout << "khong co" << std::endl;

    if (double_array.size > 0) std::cout << double_array.min() << std::endl;
    else std::cout << "khong co" << std::endl;

    if (fraction_array.size > 0) std::cout << fraction_array.min() << std::endl;
    else std::cout << "khong co" << std::endl;
}
