#include <iostream>

struct Rectangle
{
    double height;
    double width;

    friend std::istream& operator >> (std::istream& input, Rectangle& figure)
    {
        input >> figure.height >> figure.width;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Rectangle figure)
    {
        output << "[HCN] " << figure.height << "," << figure.width;
        return output;
    }

    double perimeter()
    {
        return (height + width) * 2;
    }

    bool operator < (Rectangle& other)
    {
        return perimeter() < other.perimeter();
    }

    double operator + (double num)
    {
        return perimeter() + num;
    }
};

int main()
{
    Rectangle rec1, rec2; std::cin >> rec1 >> rec2;

    std::cout << rec1 << std::endl;
    std::cout << rec2 << std::endl;
    std::cout << (rec1 < rec2 ? "true" : "false") << std::endl;
    return 0;
}