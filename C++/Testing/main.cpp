#include <iostream>

void count_down(int count)
{
    std::cout << "push " << count << '\n';

    if (count > 1) // termination condition
        count_down(count - 1);

    std::cout << "pop " << count << '\n';
}

int main()
{
    int n; std::cin >> n;

    count_down(n);
    
    return 0;
}