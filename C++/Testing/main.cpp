#include <iostream>
#include <cmath>
#include <iomanip>

struct Point
{
    int x, y;

    friend std::istream& operator>>(std::istream& input, Point& pt)
    {
        input >> pt.x >> pt.y;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Point pt)
    {
        output << "(" << pt.x << "," << pt.y << ")";
        return output;
    }

    double operator-(const Point& other) const
    {
        return std::sqrt(
            (x - other.x) * (x - other.x) +
            (y - other.y) * (y - other.y)
        );
    }

    bool operator==(const Point& other) const
    {
        return x == other.x and y == other.y;
    }
};

struct Circle
{
    Point central;
    int radius;

    const double Pi = 3.14;

    friend std::istream& operator>>(std::istream& input, Circle& circle)
    {
        input >> circle.central >> circle.radius;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, Circle circle)
    {
        output << circle.central << " " << circle.radius;
        return output;
    }

    double circumference() const
    {
        return Pi * 2 * radius;
    }

    double area() const
    {
        return Pi * radius * radius;
    }

    bool operator==(const Circle& other) const
    {
        return circumference() == other.circumference();
    }

    bool operator<(const Circle& other) const
    {
        return circumference() < other.circumference();
    }

    double operator+(const Circle& other) const
    {
        return area() + other.area();
    }

    std::string relative_position(const Circle& other) const
    {
        double dist = central - other.central;
        double sum = radius + other.radius;
        double diff = std::abs(radius - other.radius);

        if (dist == 0) return "DT";
        if (abs(radius - other.radius) < dist and dist < radius + other.radius) return "C";
        if (abs(radius - other.radius) == dist) return "TXT";
        if (abs(radius - other.radius) > dist) return "DN";
        if (radius + other.radius == dist) return "TXN";
        if (radius + other.radius < dist) return "NN";
        return "C";
    }
};

int main()
{
    Circle c1, c2;

    std::cin >> c1 >> c2;

    std::cout << c1 << std::endl;
    std::cout << c2 << std::endl;

    double sumarea = c1.area() + c2.area();
    std::cout << roundf(sumarea * 1000) / 1000 << std::endl;    

    if (c1 == c2) std::cout << "1 = 2" << std::endl; 
    else if (c1 < c2) std::cout << "1 < 2" << std::endl;
    else std::cout << "1 > 2" << std::endl;

    std::cout << c1.relative_position(c2) << std::endl;
    return 0;
}