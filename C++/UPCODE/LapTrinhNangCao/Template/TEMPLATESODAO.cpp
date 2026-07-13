#include <iostream>

struct SoDao
{
    int num;

    friend std::istream& operator >> (std::istream& input, SoDao& sd)
    {
        input >> sd.num;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, SoDao sd)
    {
        output << "[SoDao] " << sd.num;
        return output;
    }

    int reversed_num()
    {
        int result = 0;
        int temp = num;
        while (temp != 0)
        {
            result = result * 10 + temp % 10;
            temp /= 10;
        }
        return result;
    }

    bool operator > (SoDao other)
    {
        return reversed_num() > other.reversed_num();
    }

    int operator + (int n)
    {
        return reversed_num() + n;
    }
};

template<typename T>
struct Array
{
    T values[99];
    int size = 0;

    friend std::istream& operator >> (std::istream& input, Array& arr)
    {
        input >> arr.values[arr.size++];
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Array arr)
    {
        if (arr.size == 0) output << "khong co\nkhong co\n";
        else
        {
            output << arr.sum() << std::endl;
            output << arr.max_num() << std::endl;
        }
        return output;
    }

    int sum()
    {
        int result = 0;
        for (int i = 0; i < size; i++)
        {
            result = values[i] + result;
        }
        return result;
    }

    T max_num()
    {
        T result = values[0];
        for (int i = 0; i < size; i++)
        {
            if (values[i] > result) result = values[i];
        }
        return result;
    }
};

int main()
{
    char order;
    Array<int> intArr;
    Array<SoDao> sdArr;

    while (std::cin >> order)
    {
        if (order == 'T') std::cin >> intArr;
        else if (order == 'D') std::cin >> sdArr;
    }

    std::cout << intArr;
    std::cout << sdArr;

    return 0;
}