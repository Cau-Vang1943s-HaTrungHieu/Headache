#include <iostream>

struct Point
{
    int x, y;

    friend std::istream& operator >> (std::istream& input, Point& pt)
    {
        input >> pt.x >> pt.y;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const Point& pt)
    {
        output << "(" << pt.x << "," << pt.y << ")";
        return output;
    }

    bool operator == (Point& other)
    {
        return (x == other.x and y == other.y);
    }

    bool operator < (Point& other)
    {
        if (x < other.x) return true;
        if (x > other.x and y < other.y) return true;
        return false;
    }

    Point operator + (Point& other)
    {
        Point result;
        result.x = x + other.x;
        result.y = y + other.y;
        return result;
    }
};

struct PointArray
{
    Point *values;
    int size;

    friend std::istream& operator >> (std::istream& input, PointArray& arr)
    {
        arr.values = new Point[100];
        arr.size = 0;
        while (input >> arr.values[arr.size]) arr.size++;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const PointArray& arr)
    {
        for (int i = 0; i < arr.size; i++) 
        {
            output << arr.values[i] << " ";
        }
        return output;
    }

    PointArray operator + (PointArray other)
    {
        int length = std::max(this->size, other.size);
        PointArray arr;
        arr.size = length;
        arr.values = new Point[length];
        for (int i = 0; i < length; i++)
        {
            arr.values[i] = this->values[i] + other.values[i];
        }
        return arr;
    }

    Point furthest_pt()
    {
        Point result = this->values[0];
        for (int i = 1; i < this->size; i++)
        {
            if (result < this->values[i]) result = this->values[i];
        }
        return result;
    }

    Point arr_sum()
    {
        Point result = this->values[0];
        for (int i = 1; i < this->size; i++)
        {
            result = result + this->values[i];
        }
        return result;
    }
};



int main()
{
    PointArray arr;

    std::cin >> arr;

    std::cout << arr.furthest_pt() << std::endl;
    std::cout << arr.arr_sum() << std::endl;

    return 0;
}
