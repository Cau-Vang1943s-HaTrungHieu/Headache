#include <iostream>
#include <iomanip>

struct Rectangle
{
    double height, width;   // Rectangle attributes must be of double

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
        return (double) (height + width) * 2;
    }

    bool operator < (Rectangle other)
    {
        return perimeter() < other.perimeter();
    }

    double operator + (double num)
    {
        return perimeter() + num;
    }
};

template<typename T>
struct Array
{
    T values[1000];
    int size = 0;

    friend std::istream& operator >> (std::istream& input, Array& arr)
    {
        T temp;
        while (input >> temp) arr.values[arr.size++] = temp;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Array arr)
    {
        for (int i = 0; i < arr.size; i++)
        {
            output << arr.values[i] << std::endl;
        }
        return output;
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
        for (int i = 0; i < size; i++) result = values[i] + result;
        return result;
    }
};

template<typename T>
void execute(char c)
{
    Array<T> arr;
    std::cin >> arr;
    std::cout << arr.min() << std::endl;
    if (c == 'H')
    {
        std::cout << std::fixed << std::setprecision(1);
    }
    std::cout << arr.sum();
    return;
}

int main()
{
    char type;
    std::cin >> type;
    switch (type)
    {
    case 'N': execute<int>('N'); break;
    case 'H': execute<Rectangle>('H'); break;
    }

    return 0;
}