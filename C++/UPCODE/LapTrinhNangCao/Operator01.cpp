#include <iostream>
#include <algorithm>

struct Fraction
{
    int num, den;

    void normalize()
    {
        int gcd = std::__gcd(num, den);
        num /= gcd;
        den /= gcd;
        if (den < 0)
        {
            num = -num;
            den = -den;
        }
    }

    friend std::istream& operator >> (std::istream& in, Fraction& f)
    {
        in >> f.num >> f.den;
        f.normalize();
        return in;
    }

    friend std::ostream& operator << (std::ostream& out, Fraction f)
    {
        out << f.num << "/" << f.den;
        return out;
    }

    bool operator < (Fraction other)
    {
        return 1LL * num * other.den < 1LL * other.num * den; // cross-multiplication
    }

    bool operator > (Fraction other)
    {
        return other < *this;
    }

    void sort()
    {

    }
};

int main()
{
    int n; std::cin >> n;
    Fraction farray[20];

    for (int i = 0; i < n; i++)
    {
        std::cin >> farray[i];
    }

    std::sort(farray, farray + n);

    for (int i = 0; i < n; i++)
    {
        std::cout << farray[i];
        if (i < n - 1) std::cout << " ";
    }

    return 0;
}