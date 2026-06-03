#include <iostream>

struct Array
{
    int a[10];
    int size;

    Array operator + (const Array& other)
    {
        Array result;

        // Result size = max of both
        result.size = (size > other.size) ? size : other.size;

        int minSize = (size < other.size) ? size : other.size;

        // Add overlapping elements
        for (int i = 0; i < minSize; i++)
        {
            result.a[i] = a[i] + other.a[i];
        }

        // Copy leftover elements from the longer array
        if (size > other.size)
        {
            for (int i = minSize; i < size; i++)
            {
                result.a[i] = a[i];
            }
        } 
        else
        {
            for (int i = minSize; i < other.size; i++)
            {
                result.a[i] = other.a[i];
            }
        }
        return result;
    }
};

std::istream& operator >> (std::istream& input, Array& arr)
{
    input >> arr.size;
    for (int i = 0; i < arr.size; i++)
    {
        input >> arr.a[i];
    }
    return input;
}

std::ostream& operator << (std::ostream& output, Array& arr)
{
    for (int i = 0; i < arr.size; i++) 
    {
        output << arr.a[i] << " ";
    }
    return output;
}

int main()
{
    Array arr1, arr2, arr_sum;
    std::cin >> arr1 >> arr2;
    
    arr_sum = arr1 + arr2;
    std::cout << arr_sum << std::endl;
    return 0;
}