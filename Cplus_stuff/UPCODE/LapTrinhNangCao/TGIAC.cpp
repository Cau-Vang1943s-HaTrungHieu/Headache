#include <iostream>
#include <cmath>

struct Point
{
    int x, y;

    int to(Point other)
    {
        return std::sqrt(std::pow(x - other.x, 2) + std::pow(y - other.y, 2));
    }

    bool operator == (Point other)
    {
        return (x == other.x and y == other.y);
    }
};

std::istream& operator >> (std::istream& input, Point& pt)
{
    input >> pt.x >> pt.y;
    return input;
}

std::ostream &operator << (std::ostream& output, Point& pt)
{
    output << "(" << pt.x << "," << pt.y << ")";
    return output;
}

struct Triangle
{
    Point a, b, c;

    int perimeter()
    {
        return a.to(b) + b.to(c) + c.to(a);
    }

    int operator + (Triangle other)
    {
        return perimeter() + other.perimeter();
    }

    bool operator < (Triangle other)
    {
        return (perimeter() < other.perimeter());
    }

    bool operator == (Triangle other)
    {
        return
        (a == other.a or a == other.b or a == other.c) and
        (b == other.a or b == other.b or b == other.c) and
        (c == other.a or c == other.b or c == other.c);
    }
};

std::istream& operator >> (std::istream& input, Triangle& tri)
{
    input >> tri.a >> tri.b >> tri.c;
    return input;
}

std::ostream& operator << (std::ostream& output, Triangle& tri)
{
    output << tri.a << tri.b << tri.c;
    return output;
}

int main()
{
    Triangle tri1, tri2;
    std::cin >> tri1 >> tri2;
    std::cout << tri1 << std::endl;
    std::cout << tri2 << std::endl;
    std::cout << (tri1 < tri2 ? "TRUE" : "FALSE") << std::endl;
    std::cout << (tri1 == tri2 ? "TRUE" : "FALSE") << std::endl;

    return 0;
}
