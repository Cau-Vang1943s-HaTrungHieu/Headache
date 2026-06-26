#include <iostream>

struct SoMoi
{
    int A;

    friend std::istream& operator >> (std::istream& input, SoMoi& somoi)
    {
        input >> somoi.A;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, SoMoi somoi)
    {
        output << "[SoMoi] " << somoi.A;
        return output;
    }

    int digitSum()
    {
        int result = 0, temp = A;
        while (temp > 0)
        {
            result += temp % 10;
            temp /= 10;
        }
        return result;
    }

    bool operator > (SoMoi& other)
    {
        return digitSum() > other.digitSum();
    }

    SoMoi operator + (SoMoi& other)
    {
        SoMoi result;
        result.A = digitSum() + other.digitSum();
        return result;
    }

    int operator + (int num)
    {
        return num + digitSum();
    }

    bool operator == (SoMoi& other)
    {
        return A == other.A;
    }
};

template<typename T>
struct Array
{
    T values[100];
    int size = 0;

    friend std::istream& operator >> (std::istream& input, Array& arr)
    {
        T temp;
        while (input >> temp) arr.values[arr.size++] = temp;
        return input;
    }

    T max()
    {
        T result = values[0];
        for (int i = 1; i < size; i++)
        {
            if (values[i] > result) result = values[i];
        }
        return result;
    }

    int max_count()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (values[i] == max()) count++;
        }
        return count;
    }

    int sum()
    {
        int result = 0;
        for (int i = 0; i < size; i++)
        {
            result = values[i] + result;;
        }
        return result;
    }
};

template<typename T>
void execute(char c)
{
    Array<T> arr;
    std::cin >> arr;
    std::cout << arr.max() << std::endl;
    std::cout << arr.max_count() << std::endl;
    std::cout << (c == 'M' ? "[SoMoi]" : "");
    std::cout << arr.sum() << std::endl;
}

int main()
{
    char c; std::cin >> c;

    switch(c)
    {
        case 'N': execute<int>('N'); break;
        case 'M': execute<SoMoi>('M'); break;
    }

    return 0;
}
