#include <iostream>

struct Array
{
    int values[10]; // fixed storage for up to 10 integers
    int size; // the actual number of elements currently in use

    int& operator [] (int index) // Index operator
    {
        return values[index];
    }

    void operator = (const Array& other) // Assignment operator (Array return type also works)
    {
        if (this != &other) // avoid overwriting current array.
        {
            size = other.size;
            for (int i = 0; i < size; i++)
            {
                values[i] = other.values[i];
            }
        }
        return;
    }

    Array operator + (const Array& other) // addition operator
    {
        Array result;
        result.size = std::max(size, other.size);

        for (int i = 0; i < result.size; i++)
        {
            if (i < size and i < other.size) result.values[i] = values[i] + other.values[i];
            else result[i] = (i < size ? values[i] : other.values[i]);
        }
        return result;
    }
 
    bool operator == (const Array& other) const // equality operator
    {
        if (size != other.size) return false;
        for (int i = 0; i < size; i++)
        {
            if (values[i] != other.values[i]) return false;
        }
        return true;
    }

    bool operator != (const Array& other) const // inequality operator
    {
        return !(*this == other);
    }
};

// The class/struct shows how you can make custom types behaving like built-in ones;
// - you can input/output them naturally
// - You can compare them with == and !=
// - You can add them with +.
// You can index them with []

std::istream& operator >> (std::istream& input, Array& arr)
{
    input >> arr.size;
    for (int i = 0; i < arr.size; i++)
    {
        input >> arr.values[i];
    }
    return input;
}

std::ostream& operator << (std::ostream& output, Array& arr)
{
    for (int i = 0; i < arr.size; i++) 
    {
        output << arr.values[i] << " ";
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