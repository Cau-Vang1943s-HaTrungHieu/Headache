#include <iostream>

int main()
{
    int N, M;
    std::cin >> N >> M;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) arr[i] = i + 1;

    int* ptr = arr;
    int* ptrEnd = arr + N;

    while (arr != ptrEnd)
    {
        int temp = M;
        
        while (--temp)
        {
            ptr++;

            if (ptr == ptrEnd) ptr = arr;
        }
        std::cout << *ptr << " ";

        for (int* i = ptr; i != ptrEnd - 1; i++)
        {
            *i = *(i + 1);
        }
        ptrEnd--;

        if (ptr == ptrEnd) ptr = arr;
    }
}