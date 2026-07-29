#include <iostream>

struct ColoredPoint
{
    int x, y;
    std::string color_code;

    friend std::istream& operator>>(std::istream& input, ColoredPoint& pt)
    {
        input >> pt.x >> pt.y >> pt.color_code;
        return input;
    }

    friend std::ostream& operator<<(std::ostream& output, ColoredPoint pt)
    {
        output << "(" << pt.x << "," << pt.y << ",#" << pt.color_code << ")";
        return output;
    }

    bool is_5DC3A8()
    {
        return color_code == "5DC3A8";
    }

    void switch_code()
    {
        if (x > y) color_code = "1F00F3";
    }
};

int main()
{
    int capacity; std::cin >> capacity;
    ColoredPoint* Parray = new ColoredPoint[capacity];

    for (int i = 0; i < capacity; i++)
    {
        std::cin >> Parray[i];
    }

    for (int i = 0; i < capacity; i++)
    {
        std::cout << Parray[i];
        if (i < capacity - 1) std::cout << " ";
    }
    std::cout << std::endl;

    int count = 0;
    for (int i = 0; i < capacity; i++)
    {
        if (Parray[i].is_5DC3A8()) count++;
    }
    std::cout << count << std::endl;

    for (int i = 0; i < capacity; i++)
    {
        Parray[i].switch_code();
    }

    for (int i = 0; i < capacity; i++)
    {
        std::cout << Parray[i];
        if (i < capacity - 1) std::cout << " ";
    }


    return 0;
}
