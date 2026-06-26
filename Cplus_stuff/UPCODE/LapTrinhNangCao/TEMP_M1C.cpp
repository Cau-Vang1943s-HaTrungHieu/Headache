#include <iostream>

template<typename T>
struct M1CArray
{
    T values[99];
    int size = 0;

    void nhap()
    {
        T temp;
        while (std::cin >> temp)
        {
            values[size++] = temp;
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

    void xuat()
    {
        std::cout << tong();
    }
};

int main()
{
    M1CArray<int> arr;

    arr.nhap();
    arr.xuat();

    return 0;
}