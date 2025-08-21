#include <iostream>
using namespace std;

struct Fraction
{
    int numerator, denominator;
};

void inputFraction(Fraction& f);
void outputFraction(Fraction f);
void simplify(Fraction& f);
int gcd(int a, int b);
Fraction findMinFrac(Fraction f[], int numOfFracs);

int main()
{
    int n;
    Fraction f[100];
    cin >> n;

    for (int i = 0; i < n; ++i) {
        inputFraction(f[i]);
    }

    Fraction minFracs = findMinFrac(f, n);
    simplify(minFracs);
    outputFraction(minFracs);

    return 0;
}

void inputFraction(Fraction& f)
{
    cin >> f.numerator >> f.denominator;
}

void outputFraction(Fraction f)
{
    cout << f.numerator << "/" << f.denominator;
}

void simplify(Fraction& f)
{
    int common = gcd(f.numerator, f.denominator);
    f.numerator /= common;
    f.denominator /= common;

    if (f.denominator < 0) {
        f.numerator = -f.numerator;
        f.denominator = -f.denominator;
    }
}
int gcd(int a, int b)
{
    while (b != 0) {
        int tmp = b;
        b = a % b;
        a = tmp;
    }
    return a;
}

Fraction findMinFrac(Fraction f[], int numOfFracs)
{
    Fraction result = f[0];
    for (int i = 0; i < numOfFracs; ++i) {
        if (f[i].numerator * result.denominator < result.numerator * f[i].denominator) {
            result = f[i];
        }
    }
    return result;
}
