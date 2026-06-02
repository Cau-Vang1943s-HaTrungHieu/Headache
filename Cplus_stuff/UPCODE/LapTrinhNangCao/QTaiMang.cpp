#include <iostream>

struct Array
{
    int a[10]; // fixed storage for up to 10 integers
    int n; // the actual number of elements currently in use

    Array& operator = (const Array& other) // Assignment operator
    {
        if (this != &other) // avoid overwriting current array.
        {
            n = other.n;
            for (int i = 0; i < n; i++)
            {
                a[i] = other.a[i];
            }
        }
        return *this;
    }

    Array operator + (const Array& other) // addition operator
    {
        Array result;
        result.n = n;
        for (int i = 0; i < n; i++)
        {
            result.a[i] = a[i] + other.a[i];
        }
        return result;
    }
 
    bool operator == (const Array& other) const // equality operator
    {
        if (n != other.n) return false;
        for (int i = 0; i < n; i++)
        {
            if (a[i] != other.a[i]) return false;
        }
        return true;
    }

    bool operator != (const Array& other) const // inequality operator
    {
        return !(*this == other);
    }

    int& operator [] (int index) // Index operator
    {
        return a[index];
    }
};

// The class/struct shows how you can make custom types behaving like built-in ones;
// - you can input/output them naturally
// - You can compare them with == and !=
// - You can add them with +.
// You can index them with []

std::istream& operator >> (std::istream& input, Array& arr)
{
    input >> arr.n;
    for (int i = 0; i < arr.n; i++)
    {
        input >> arr.a[i];
    }
    return input;
}

std::ostream& operator << (std::ostream& output, Array& arr)
{
    for (int i = 0; i < arr.n; i++) 
    {
        output << arr.a[i] << " ";
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

    return 0;
}