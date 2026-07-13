#include <iostream>
#include <cmath>
#include <algorithm>

struct Point
{
    int x, y;

    friend std::istream& operator >> (std::istream& input, Point& pt)
    {
        input >> pt.x >> pt.y;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Point pt)
    {
        output << "(" << pt.x << "," << pt.y << ")";
        return output;
    }

    double operator - (const Point& other) const
    {
        return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
    }

    bool operator < (const Point& other) const // Must be const for the lambda to work
    {
        if (x != other.x) return x < other.x;
        return y < other.y;
    }
};

struct Point3D
{
    int x, y, z;

    friend std::istream& operator >> (std::istream& input, Point3D& pt)
    {
        input >> pt.x >> pt.y >> pt.z;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Point3D pt)
    {
        output << "(" << pt.x << ", " << pt.y << ", " << pt.z << ")";
        return output;
    }

    double operator - (const Point3D& other) const
    {
        return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y) + (other.z - z) * (other.z - z));
    }

    bool operator < (const Point3D& other) const // Must be const for the lambda to work
    {
        if (x != other.x) return x < other.x;
        if (y != other.y) return y < other.y;
        return z < other.z;
    }
};

template<typename T>
struct GeometricArray
{
    T values[99];
    int size = 0;

    friend std::istream& operator >> (std::istream& input, GeometricArray& arr)
    {
        if (arr.size < 99)
        {
            input >> arr.values[arr.size++];
        }
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, GeometricArray arr)
    {
        for (int i = 0; i < arr.size; i++)
        {
            output << arr.values[i] << " ";
        }
        return output;
    }

    double maxDistance()
    {
        double result = 0;
        for (int i = 0; i < size; i++)
        {
            for (int j = i + 1; j < size; j++)
            {
                double distance = values[i] - values[j];
                if (distance > result) result = distance;
            }
        }
        return result;
    }

    void sortAsc()
    {
        std::sort(values, values + size);
    }

    void sortDsc()  // Use lambda expression
    {
        std::sort(values, values + size,
            [](const T& a, const T& b)
            {
                return b < a;
            }
        );
    }
};

int main()
{
    GeometricArray<Point> arr2D;
    GeometricArray<Point3D> arr3D;
    std::string type;

    while (std::cin >> type)
    {
        if (type == "Oxy") std::cin >> arr2D;
        else if (type == "Oxyz") std::cin >> arr3D;
    }

    arr2D.sortAsc();
    arr3D.sortDsc();

    std::cout << arr2D << std::endl;
    std::cout << arr3D << std::endl;
    std::cout << roundf(arr2D.maxDistance() * 1000) / 1000 << std::endl;
    std::cout << roundf(arr3D.maxDistance() * 1000) / 1000 << std::endl;

    return 0;
}