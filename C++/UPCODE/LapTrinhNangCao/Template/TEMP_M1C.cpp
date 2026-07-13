#include <iostream>

struct M1C
{
    int values[99];
    int size = 0;
    void nhap()
    {
        int temp;
        while (std::cin >> temp)
        {
            values[size++] = temp;
        }
    }

    void xuat()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << values[i] << " ";
        }
    }

    int tong()
    {
        int result = 0;
        for (int i = 0; i < size; i++)
        {
            result += values[i];
        }
        return result;
    }
};

int main()
{
    M1C array;
    array.nhap();
    std::cout << array.tong() << std::endl;

    return 0;
}