#include <iostream>

template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

// swapping two array
template<typename T>
void swap(T a[], T b[], int size)
{
    for (int i = 0; i < size; i++)
    {
        T temp = a[i];
        a[i] = b[i];
        b[i] = temp;
    }
}
/*
You can see that we don't pass a and b ass references because they are array which are already pointers,
so passing them into a function will just make their pointers "decayed"
*/

int main()
{
    std::cout << "Swapping two integers:" << std::endl;
    int a, b;
    std::cin >> a >> b;
    std::cout << "Before swapping: " << a << " " << b << std::endl;
    swap(a, b);
    std::cout << "After swapping: " << a << " " << b << std::endl;

    std::cout << "Swapping two strings:" << std::endl;
    std::string x, y;
    std::cin >> x >> y;
    std::cout << "Before swapping: " << x << " " << y << std::endl;
    swap(x, y);
    std::cout << "After swapping: " << x << " " << y << std::endl;

    std::cout << "Swapping arrays:" << std::endl;
    int SIZE = 9;
    int zeroes[] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
    int ones[] = {1, 1, 1, 1, 1, 1, 1, 1, 1};
    std::cout << "Before swapping:" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << zeroes[i] << " " << ones[i] << "\t";
    }
    std::cout << std::endl;

    swap(zeroes, ones, SIZE);

    std::cout << "After swapping:" << std::endl;
    for (int i = 0; i < SIZE; i++)
    {
        std::cout << zeroes[i] << " " << ones[i] << "\t";
    }

    return 0;
}
