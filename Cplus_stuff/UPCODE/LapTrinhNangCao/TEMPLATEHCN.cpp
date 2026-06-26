#include <iostream>
#include <iomanip>

struct Rectangle
{
    int width, height;

    friend std::istream& operator >> (std::istream& input, Rectangle& figure)
    {
        input >> figure.width >> figure.height;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Rectangle figure)
    {
        output << "[HCN] " << figure.width << "," << figure.height;
        return output;
    }

    double perimeter() const
    {
        return (double) (width + height) * 2;
    }

    bool operator < (Rectangle& other)
    {
        return perimeter() < other.perimeter();
    }

    double operator + (double n)
    {
        return perimeter() + n;
    }
};

double operator + (double n, const Rectangle& rectangle)
{
    return n + rectangle.perimeter();
}

template<typename T>
struct Array
{
    T values[100];
    int size = 0;

    friend std::istream& operator >> (std::istream& input, Array& arr)
    {
        T temp;
        while (input >> temp)
        {
            arr.values[arr.size++] = temp;
        }
        return input;
    }

    T min()
    {
        T result = values[0];
        for (int i = 1; i < size; i++)
        {
            if (values[i] < result) result = values[i];
        }
        return result;
    }

    double sum()
    {
        double result = 0;
        for (int i = 0; i < size; i++)
        {
            result = values[i] + result;
        }
        return result;
    }
};

template<typename T>
void execute(char c)
{
    Array<T> arr;
    std::cin >> arr;
    std::cout << arr.min() << std::endl;
    if (c == 'H') std::cout << std::fixed << std::setprecision(1);
    std::cout << arr.sum();
    return;
}

int main()
{
    char c; std::cin >> c;

    switch (c)
    {
        case 'N': execute<int>('N'); break;
        case 'H': execute<Rectangle>('H'); break;
    }

    return 0;
}