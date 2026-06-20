#include <iostream>

struct Array
{
    int values[99];
    int s1ze = 0;

    int operator [] (int index)
    {
        return values[index];
    }

    friend std::istream& operator >> (std::istream& input, Array& arr)
    {
        input >> arr.s1ze;
        for (int i = 0; i < arr.s1ze; i++)
        {
            input >> arr.values[i];
        }
        return input;
    }

    friend std::ostream& operator << (std::ostream& output, Array arr)
    {
        for (int i = 0; i < arr.s1ze; i++)
        {
            output << arr.values[i] << " ";
        }
        return output;
    }

    Array& operator = (Array& other)
    {
        s1ze = other.s1ze;
        if (*this != other)
        {
            for (int i = 0; i < s1ze; i++)
            {
                this->values[i] = other.values[i];
            }
        }
        return *this;
    }

    Array& operator + (Array& other)
    {
        Array result;
        result.s1ze = s1ze;
        for (int i = 0; i < s1ze; i++)
        {
            result.values[i] = values[i] + other.values[i];
        }
        return result;
    }

    bool operator == (Array& other)
    {
        if (s1ze != other.s1ze) return false;
        for (int i = 0; i < s1ze; i++)
        {
            if (values[i] != other.values[i]) return false;
        }
        return true;
    }

    bool operator != (Array& other)
    {
        return !(*this == other);
    }
};

int main()
{
    Array arr1, arr2; std::cin >> arr1 >> arr2;

    std::cout << (arr1 == arr2 ? "yes" : "no") << std::endl;

    return 0;
}
