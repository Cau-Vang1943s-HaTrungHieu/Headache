#include <iostream>

struct SoMoi
{
    int A;

    friend std::istream& operator >> (std::istream& input, SoMoi& sm)
    {
        input >> sm.A;
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, const SoMoi sm)
    {
        output << "[SoMoi] " << sm.A;
        return output;
    }

    int digits_sum()
    {
        int sum = 0;
        int temp = A;
        while (temp != 0)
        {
            sum += temp % 10;
            temp /= 10;
        }
        return sum;
    }

    bool operator > (SoMoi other)
    {
        return digits_sum() > other.digits_sum();
    }

    SoMoi operator + (SoMoi other)
    {
        SoMoi result;
        result.A = digits_sum() + other.digits_sum();
        return result;
    }

    bool operator == (SoMoi other)
    {
        return A == other.A;
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

    T maxNum()
    {
        T result = values[0];
        for (int i = 0; i < size; i++)
        {
            if (values[i] > result) result = values[i];
        }
        return result;
    }

    int maxNum_count()
    {
        int count = 0;
        for (int i = 0; i < size; i++)
        {
            if (values[i] == maxNum()) count++;
        }
        return count;
    }

    T sum()
    {
        T result{0};
        for (int i = 0; i < size; i++)
        {
            result = result + values[i];
        }
        return result;
    }
};

template<typename T>
void execute(char choice)
{
    Array<T> arr;
    std::cin >> arr;
    std::cout << arr.maxNum() << std::endl;
    std::cout << arr.maxNum_count() << std::endl;
    std::cout << arr.sum() << std::endl;
}

int main()
{
    char choice; std::cin >> choice;
    switch (choice)
    {
    case 'N': execute<int>(choice); break;
    case 'M': execute<SoMoi>(choice); break;
    }
    return 0;
}