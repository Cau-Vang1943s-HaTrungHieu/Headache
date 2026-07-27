#include <iostream>
#include <cmath>
#include <algorithm>

struct Line
{
    int a, b, c;

    friend std::istream& operator>>(std::istream& input, Line& line)
    {
        input >> line.a >> line.b >> line.c;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Line line)
    {
        if (line.a != 0)
        {
            if (line.a < 0) output << "-";
            if (abs(line.a) != 1) output << abs(line.a);
            output << "x";
        }

        if (line.b != 0)
        {
            if (line.b > 0 and line.a != 0) output << " + ";
            if (line.b < 0 and line.a != 0) output << " - ";
            if (line.b < 0 and line.a == 0) output << "-";
            if (abs(line.b) != 1) output << abs(line.b);
            output << "y";
        }

        if (line.c != 0)
        {
            if (line.c > 0) output << " + " << line.c;
            if (line.c < 0) output << " - " << -line.c;
        }

        output << " = 0";
        return output;
    }

    bool operator == (Line other)
    {
        return a == other.a and b == other.b and c == other.c;
    }
};

struct Fraction
{
    int numerator;
    int denominator;

    void normalize()
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

    friend std::ostream& operator<<(std::ostream& output, Fraction frac)
    {
        output << frac.numerator << "/" << frac.denominator;
        return output;
    }

    double operator*(int x)
    {
        return (double) numerator * x / denominator;
    }
};

char relative_position(int D, int Dx, int Dy, int Dv)
{
    if (Dv == 0) return 'V';
    if (D != 0) return 'C';
    else
    {
        if (Dx == Dy and Dy == 0) return 'T';
        if (Dx != 0 or Dy != 0) return 'S';
    }
    return '\n';
}

void print(Line line1, Line line2)
{
    line1.c = -line1.c;
    line2.c = -line2.c;
    int D = line1.a * line2.b - line2.a * line1.b;
    int Dx = line1.c * line2.b - line2.c * line1.b;
    int Dy = line1.a * line2.c - line2.a * line1.c;
    int Dv = line1.a * line2.a + line1.b * line2.b;

    char position = relative_position(D, Dx, Dy, Dv);
    std::cout << position << std::endl;

    if (position == 'C' or position == 'V')
    {
        Fraction x, y;
        x.numerator = Dx; x.denominator = D; x.normalize();
        y.numerator = Dy; y.denominator = D; y.normalize();

        std::cout << "(";
        if (x.numerator % x.denominator == 0) std::cout << x.numerator / x.denominator;
        else std::cout << x;
        std::cout << ", ";

        if (y.numerator % y.denominator == 0) std::cout << y.numerator / y.denominator;
        else std::cout << y;
        std::cout << ")";
    }
    else if (position == 'S')
    {
        int x = 1;
        double y = (double) (-line2.c - line2.a * x) / line2.b;
        double dist = abs(line1.a * x + line1.b * y + line1.c) / std::sqrt(line1.a * line1.a + line1.b * line1.b);
        std::cout << roundf(dist * 1000) / 1000;
    }
    else if (position == 'T') std::cout << 0;
}

int main()
{
    Line line1, line2;
    std::cin >> line1 >> line2;

    std::cout << line1 << std::endl;
    std::cout << line2 << std::endl;

    print(line1, line2);

    return 0;
}