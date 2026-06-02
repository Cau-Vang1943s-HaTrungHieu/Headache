#include <iostream>

struct Array
{
    int a[10];
    int n;

    Array& operator = (const Array& other)
    {
        if (this != &other)
        {
            n = other.n;
            for (int i = 0; i < n; i++) 
            {
                a[i] = other.a[i];
            }
        }
        return *this;
    }

    Array operator + (Array& other)
    {
        Array result;
        result.n = n;
        for (int i = 0; i < n; i++) 
        {
            result.a[i] = a[i] + other.a[i];
        }
        return result;
    }

    bool operator == (Array other)
    {
        if (n != other.n) return false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != other.a[i]) return false;
        }
        return true;
    }

    bool operator != (Array other)
    {
        return !(*this == other);
    }

    int& operator [] (int index)
    {
        return a[index];
    }
};

std::istream& operator >> (std::istream& input, Array& arr) 
{
    input >> arr.n;
    for (int i = 0; i < arr.n; i++)
    {
        input >> arr[i];
    }
    return input;
}

std::ostream& operator << (std::ostream& output, Array& arr)
{
    for (int i = 0; i < arr.n; i++)
    {
        output << arr[i];
    }
    return output;
}


int main()
{
    Array arr1, arr2;
    std::cin >> arr1;
    std::cin >> arr2;

    if (arr1 == arr2) std::cout << "yes";
    else std::cout << "no";
    std::cout <<  std::endl;

    return 0;
}